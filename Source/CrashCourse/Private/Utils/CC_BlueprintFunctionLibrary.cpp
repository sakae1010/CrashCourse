// Copyright sakae


#include "Utils/CC_BlueprintFunctionLibrary.h"

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
