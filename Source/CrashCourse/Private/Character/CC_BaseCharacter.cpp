// Copyright sakae


#include "CrashCourse/Public/Character/CC_BaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"

ACC_BaseCharacter::ACC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	//無論是否渲染都會 Tick 並刷新骨骼變換 - 用於專用伺服器上的骨骼更新
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* ACC_BaseCharacter::GetAbilitySystemComponent() const
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
