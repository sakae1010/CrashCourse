// Copyright sakae

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CC_BaseCharacter.generated.h"

struct FOnAttributeChangeData;
class UGameplayEffect;
class UGameplayAbility;
class UAttributeSet;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialed , UAbilitySystemComponent* ,ASC , UAttributeSet* , AS);

UCLASS(Abstract)
class CRASHCOURSE_API ACC_BaseCharacter : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACC_BaseCharacter();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const;
	bool IsAlive() const { return bAlive; }
	void SetAlive(const bool bAliveStatus) { bAlive = bAliveStatus;}
	
	UPROPERTY(BlueprintAssignable)
	FASCInitialed OnASCInitialed;
	
	UFUNCTION(BlueprintCallable , Category="Crash|Death")
	void HandleRespawn();
	
protected:
	void GiveStartAbilities();
	void InitializeAttributes();
	void OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData);
	virtual void OnHandleDeath();
private:
	UPROPERTY(EditDefaultsOnly , Category="Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category= "Crash | Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
	
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true") ,Replicated)
	bool bAlive = true;
	
};
