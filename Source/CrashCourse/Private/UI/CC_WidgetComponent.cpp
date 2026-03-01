// Copyright sakae


#include "UI/CC_WidgetComponent.h"

#include "AbilitySystem/CC_AbilitySystemComponent.h"
#include "AbilitySystem/CC_AttributeSet.h"
#include "Character/CC_BaseCharacter.h"


void UCC_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilitySystemSet();
	
	if (!IsASCInitialed())
	{
		CrashCharacter->OnASCInitialed.AddDynamic(this,&ThisClass::OnASCInitialed);
	}
}

void UCC_WidgetComponent::InitAbilitySystemSet()
{
	CrashCharacter = Cast<ACC_BaseCharacter>(GetOwner());
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(CrashCharacter->GetAbilitySystemComponent());
	AttributeSet = Cast<UCC_AttributeSet>(CrashCharacter->GetAttributeSet());
}

bool UCC_WidgetComponent::IsASCInitialed() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UCC_WidgetComponent::OnASCInitialed(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UCC_AttributeSet>(AS);
	
	// TODO: 檢查 Attribute Set 是否已經用第一個 GE 初始化
	// 如果沒有，綁定到某個委派，當它初始化時會廣播。
}
