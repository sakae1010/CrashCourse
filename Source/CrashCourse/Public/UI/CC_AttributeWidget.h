// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "CC_AttributeWidget.generated.h"

class UCC_AttributeSet;
struct FGameplayAttribute;
/**
 * 
 */
UCLASS()
class CRASHCOURSE_API UCC_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category= "Crash|Attribute");
	FGameplayAttribute Attribute;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category= "Crash|Attribute");
	FGameplayAttribute MaxAttribute;
	
	void OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair , const UCC_AttributeSet* AttributeSet);
	
	bool MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;
	
	UFUNCTION(BlueprintImplementableEvent , meta=(DisplayName="OnAttributeChanged"))
	void BP_OnAttributeChanged(float NewValue , float NewMaxValue);
};
