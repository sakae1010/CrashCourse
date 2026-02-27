// Copyright sakae


#include "AbilitySystem/CC_AbilitySystemComponent.h"


UCC_AbilitySystemComponent::UCC_AbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UCC_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


void UCC_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

