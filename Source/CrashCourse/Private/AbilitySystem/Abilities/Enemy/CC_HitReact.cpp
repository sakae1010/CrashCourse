// Copyright sakae


#include "AbilitySystem/Abilities/Enemy/CC_HitReact.h"

void UCC_HitReact::CacheHitDirectionVector(AActor* Instigator)
{
	AvatarForward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector AvatarLocation = GetAvatarActorFromActorInfo()->GetActorLocation();
	const FVector InstigatorLocation = Instigator->GetActorLocation();
	ToInstigator = InstigatorLocation - AvatarLocation;
	ToInstigator.Normalize();
}
