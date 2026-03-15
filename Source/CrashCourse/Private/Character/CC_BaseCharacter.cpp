// Copyright sakae


#include "CrashCourse/Public/Character/CC_BaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"
#include "Net/UnrealNetwork.h"

ACC_BaseCharacter::ACC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	//無論是否渲染都會 Tick 並刷新骨骼變換 - 用於專用伺服器上的骨骼更新
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	
}

void ACC_BaseCharacter::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ThisClass, bAlive);
}

UAbilitySystemComponent* ACC_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

UAttributeSet* ACC_BaseCharacter::GetAttributeSet() const
{
	return nullptr;
}


void ACC_BaseCharacter::GiveStartAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	 for (const TSubclassOf<UGameplayAbility>& Ability : StartAbilities)
	 {
		if (Ability == nullptr)	return;	
	 	FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
	 	GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	 }
}

void ACC_BaseCharacter::InitializeAttributes()
{
	checkf(IsValid(InitializeAttributesEffect),TEXT("InitializeAttributesEffect is not set."));

	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(InitializeAttributesEffect,1,ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

}

void ACC_BaseCharacter::OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData)
{
	 if (AttributeChangeData.NewValue <= 0.f && bAlive)
	 {
	 	OnHandleDeath();
	 }
}

void ACC_BaseCharacter::OnHandleDeath()
{
	bAlive = false;
	if (IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("%s is dead!"),*GetName());
	}
}
void ACC_BaseCharacter::HandleRespawn()
{
	bAlive = true;
}
