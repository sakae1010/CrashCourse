// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CC_GameplayAbility.h"
#include "CC_Primary.generated.h"

/**
 * 
 */
UCLASS()
class CRASHCOURSE_API UCC_Primary : public UCC_GameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable , Category = "Crash|Abilities")
	TArray<AActor*> HitBoxOverlapTest();
	
	UFUNCTION(BlueprintCallable , Category = "Crash|Abilities")
	void SendHitReactEventToActors(const TArray<AActor*>& ActorsHit);
	
private:
	
	void DrawHitBox(const 	TArray<FOverlapResult>& OverlapResults , const FVector& HitBoxLocation) const;
	
	UPROPERTY(EditDefaultsOnly, Category= "Crash|Abilities")
	float HitBoxRadius = 100.0f;
	
	UPROPERTY(EditDefaultsOnly, Category= "Crash|Abilities")
	float HitBoxForwardOffset = 200.0f;
	
	UPROPERTY(EditDefaultsOnly, Category= "Crash|Abilities")
	float HitBoxElevationOffset = 20.0f;
};
