// Copyright sakae


#include "Utils/CC_BlueprintFunctionLibrary.h"

#include "Character/CC_BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

EHitDirection UCC_BlueprintFunctionLibrary::GetHitDirection(const FVector& TargetForward,const FVector& ToInstigator)
{
	const float Dot = FVector::DotProduct(TargetForward, ToInstigator);
	if (Dot <-0.5)
	{
		return EHitDirection::Back;
	}
	if (Dot < 0.5)
	{
		const FVector Cross = FVector::CrossProduct(TargetForward, ToInstigator);
		if (Cross.Z < 0.f)
		{
			return EHitDirection:: Left;
		}	
		return EHitDirection::Right;
	}
	return EHitDirection::Forward;
}

FName UCC_BlueprintFunctionLibrary::GetHitDirectionName(EHitDirection HitDirection)
{
	switch (HitDirection)
	{
		case EHitDirection :: Left: return FName("Left");
		case EHitDirection :: Right: return FName("Right");
		case EHitDirection :: Forward: return FName("Forward");
		case EHitDirection :: Back: return FName("Back");
		default: return FName("None");
	}
}

FClosetActorWithTagResult UCC_BlueprintFunctionLibrary::FindClosetActorWithTag(const UObject* WorldContextObject, const FName& Tag, const FVector& Origin, float Radius)
{
	TArray<AActor*> ActorsWithTag;
	UGameplayStatics::GetAllActorsWithTag(WorldContextObject->GetWorld(), Tag, ActorsWithTag);
	float ClosestDistance = TNumericLimits<float>::Max();
	AActor* ClosestActor = nullptr;
	
	for (AActor* Actor : ActorsWithTag)
	{
		if (!IsValid(Actor))
		{
			continue;
		}
		ACC_BaseCharacter* const BaseCharacter = Cast<ACC_BaseCharacter>(Actor);
		if (!IsValid(BaseCharacter) || !BaseCharacter->IsAlive())
		{
			continue;
		}
		
		
		const float Distance = (Actor->GetActorLocation() - Origin).Size();
		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			ClosestActor = Actor;
		}
	}
	FClosetActorWithTagResult Result;
	Result.Actor = ClosestActor;
	Result.Distance = ClosestDistance;
	return  Result;
}
