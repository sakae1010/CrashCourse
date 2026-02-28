// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CC_BaseCharacter.generated.h"

class UGameplayEffect;
class UGameplayAbility;

UCLASS(Abstract)
class CRASHCOURSE_API ACC_BaseCharacter : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACC_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	void GiveStartAbilities();
	void InitializeAttributes();
private:
	UPROPERTY(EditDefaultsOnly , Category="Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category= "Crash | Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
	
};
