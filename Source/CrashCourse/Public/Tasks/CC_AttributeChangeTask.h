// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/CC_AttributeSet.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "CC_AttributeChangeTask.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAttributeChange, FGameplayAttribute, Attribute, float, NewValue, float, OldValue);

UCLASS(BlueprintType, meta = (ExposedAsyncProxy = AsyncTask))
class CRASHCOURSE_API UCC_AttributeChangeTask : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChange OnAttributeChange;
	
	
	UFUNCTION(BlueprintCallable)
	static UCC_AttributeChangeTask* ListenForAttributeChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAttribute Attribute);
	
	UFUNCTION(BlueprintCallable)
	void EndTask();

	void AttributeChanged(const FOnAttributeChangeData& Data) const;
	TWeakObjectPtr<UAbilitySystemComponent> ASC;
	FGameplayAttribute AttributeToListenFor;
};
