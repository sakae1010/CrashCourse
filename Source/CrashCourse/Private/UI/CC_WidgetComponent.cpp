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
		return;
	}
	InitializeAttributeDelegate();
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

void UCC_WidgetComponent::InitializeAttributeDelegate()
{
	if (!AttributeSet->bAttributeSetInitialized)
	{
		AttributeSet->OnAttributeSetInitialized.AddDynamic(this,&ThisClass::BindToAttributeChanges);
	}
	else
	{
		 BindToAttributeChanges();
	}
}

void UCC_WidgetComponent::OnASCInitialed(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UCC_AttributeSet>(AS);
	
	if (!IsASCInitialed()) return;
	InitializeAttributeDelegate();
}

void UCC_WidgetComponent::BindToAttributeChanges()
{
	//TODO : Listen For Changes To Gameplay Attribute and update our widgets Accordingly
}
