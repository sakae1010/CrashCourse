// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CC_BlueprintFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EHitDirection : uint8
{
	Left    UMETA(DisplayName = "Left"),
	Right   UMETA(DisplayName = "Right"),
	Forward UMETA(DisplayName = "Forward"),
	Back    UMETA(DisplayName = "Back"),
};

UCLASS()
class CRASHCOURSE_API UCC_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category = "Crash|Utils")
	static EHitDirection GetHitDirection(const FVector& TargetForward,const FVector& ToInstigator);
	
	UFUNCTION(BlueprintPure, Category = "Crash|Utils")
	static FName GetHitDirectionName(EHitDirection HitDirection);
};
