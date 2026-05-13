// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "CC_BaseCharacter.h"
#include "CC_EnemyCharacter.generated.h"

class UAttributeSet;

UCLASS()
class CRASHCOURSE_API ACC_EnemyCharacter : public ACC_BaseCharacter
{
	GENERATED_BODY()

public:
	ACC_EnemyCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const override;

	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Crash|AI")
	float AcceptanceRadius {500.f};
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Crash|AI")
	float MinAttackDelay{.5f};

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Crash|AI")
	float MaxAttackDelay{.5f};
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Crash|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent; 
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
