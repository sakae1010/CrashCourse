// Copyright sakae


#include "AbilitySystem/Abilities/Player/CC_Primary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Engine/OverlapResult.h"
#include "GameplayTags/CCTags.h"

TArray<AActor*> UCC_Primary::HitBoxOverlapTest()
{
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetAvatarActorFromActorInfo());
	
	//確保過濾使用者
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActors(ActorsToIgnore);
	
	FCollisionResponseParams ResponseParams;
	ResponseParams.CollisionResponse.SetAllChannels(ECollisionResponse::ECR_Ignore);
	ResponseParams.CollisionResponse.SetResponse(ECC_Pawn, ECollisionResponse::ECR_Block);

	TArray<FOverlapResult> OverlapResults;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(HitBoxRadius);
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector() * HitBoxForwardOffset;
	const FVector HitBoxLocation = GetAvatarActorFromActorInfo()->GetActorLocation() + Forward + FVector(0, 0, HitBoxElevationOffset);
	GetWorld()->OverlapMultiByChannel(OverlapResults,HitBoxLocation, FQuat::Identity, ECC_Visibility, Sphere, QueryParams, ResponseParams);
	
	TArray<AActor*> ActorsHit;
	for (const FOverlapResult& OverlapResult : OverlapResults)
	{
		AActor* Actor = OverlapResult.GetActor();
		if (!IsValid(Actor)) continue;
		ActorsHit.AddUnique(Actor);
	}
	
	if (bDrawDebugs)
	{
		DrawHitBox(OverlapResults, HitBoxLocation);
	}
	return ActorsHit;
}

void UCC_Primary::SendHitReactEventToActors(const TArray<AActor*>& ActorsHit)
{
	for (AActor* HitActor: ActorsHit)
	{
		FGameplayEventData Payload;
		Payload.Instigator = GetAvatarActorFromActorInfo();
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitActor, CCTags::Events::Enemy::HitReact, Payload);
	}
}

void UCC_Primary::DrawHitBox(const TArray<FOverlapResult>& OverlapResults, const FVector& HitBoxLocation) const
{
	DrawDebugSphere(GetWorld(), HitBoxLocation, HitBoxRadius, 16, FColor::Red, false, 3.0f);

	for (const FOverlapResult& OverlapResult : OverlapResults)
	{
		if (AActor* Actor = OverlapResult.GetActor(); IsValid(Actor))
		{
			FVector DebugLocation = Actor->GetActorLocation();
			DebugLocation.Z+=100.f;
			DrawDebugSphere(GetWorld(), DebugLocation, 30.f, 10, FColor::Green, false, 3.0f);
				
		}
	}
}
