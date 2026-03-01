// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/WidgetTree.h"
#include "CC_WidgetComponent.generated.h"

struct FGameplayAttribute;
class UAbilitySystemComponent;
class UCC_AttributeSet;
class UCC_AbilitySystemComponent;
class ACC_BaseCharacter;
class UCC_AttributeWidget;
class UWidget;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRASHCOURSE_API UCC_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()


protected:
	UPROPERTY(EditAnywhere,Category= "Crash|Attributes")
	TMap<FGameplayAttribute,FGameplayAttribute> AttributeMap;
	
	// Called when the game starts
	virtual void BeginPlay() override;
private:
	TWeakObjectPtr<ACC_BaseCharacter> CrashCharacter;
	TWeakObjectPtr<UCC_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UCC_AttributeSet> AttributeSet;
	
	void InitAbilitySystemSet();
	bool IsASCInitialed() const;
	void InitializeAttributeDelegate();
	void BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;
	UFUNCTION()
	void OnASCInitialed(UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	UFUNCTION()
	void BindToAttributeChanges();
};
