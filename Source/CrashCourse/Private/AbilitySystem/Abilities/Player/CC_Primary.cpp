// Copyright sakae


#include "AbilitySystem/Abilities/Player/CC_Primary.h"

#include "Engine/OverlapResult.h"

void UCC_Primary::HitBoxOverlapTest()
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
	
	if (bDrawDebugs)
	{
		DrawDebugSphere(GetWorld(), HitBoxLocation, HitBoxRadius, 16, FColor::Red, false, 3.0f);

		for (FOverlapResult& OverlapResult : OverlapResults)
		{
			if (AActor* Actor = OverlapResult.GetActor(); IsValid(Actor))
			{
				FVector DebugLocation = Actor->GetActorLocation();
				DebugLocation.Z+=100.f;
				DrawDebugSphere(GetWorld(), DebugLocation, 30.f, 10, FColor::Green, false, 3.0f);
				
			}
		}
	}
	
	
	
	

}
