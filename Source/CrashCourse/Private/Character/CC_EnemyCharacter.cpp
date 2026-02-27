// Copyright sakae


#include "Character/CC_EnemyCharacter.h"
#include "AbilitySystemComponent.h"


ACC_EnemyCharacter::ACC_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");	
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}

UAbilitySystemComponent* ACC_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACC_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(this,this);
	
	if (!HasAuthority()) return;
	
	GiveStartAbilities();
}
