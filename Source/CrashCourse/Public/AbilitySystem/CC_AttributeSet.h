// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CC_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
UCLASS()
class CRASHCOURSE_API UCC_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	
	virtual  void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(BlueprintReadOnly, Category = "Crash|Attributes")
	FGameplayAttributeData Health;
		
	UPROPERTY(BlueprintReadOnly, Category = "Crash|Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Crash|Attributes", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	
	UPROPERTY(BlueprintReadOnly, Category = "Crash|Attributes", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldValue);
	
	ATTRIBUTE_ACCESSORS(ThisClass, Health)
	ATTRIBUTE_ACCESSORS(ThisClass, MaxHealth)
	ATTRIBUTE_ACCESSORS(ThisClass, Mana)
	ATTRIBUTE_ACCESSORS(ThisClass, MaxMana)
	
};
