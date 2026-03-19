// Copyright sakae


#include "Tasks/CC_AttributeChangeTask.h"

#include "AbilitySystemComponent.h"

UCC_AttributeChangeTask* UCC_AttributeChangeTask::ListenForAttributeChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAttribute Attribute)
{
	UCC_AttributeChangeTask* WaitForAttributeChangeTask = NewObject<UCC_AttributeChangeTask>();
	WaitForAttributeChangeTask->ASC = AbilitySystemComponent;
	WaitForAttributeChangeTask->AttributeToListenFor = Attribute;

	if (!IsValid(AbilitySystemComponent))
	{
		WaitForAttributeChangeTask->RemoveFromRoot();
		return nullptr;
	}
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(WaitForAttributeChangeTask, &UCC_AttributeChangeTask::AttributeChanged);

	return WaitForAttributeChangeTask;
	
}

void UCC_AttributeChangeTask::EndTask()
{
	if (ASC.IsValid())
	{
		ASC->GetGameplayAttributeValueChangeDelegate(AttributeToListenFor).RemoveAll(this);
	}
	SetReadyToDestroy();
	MarkAsGarbage();
}

void UCC_AttributeChangeTask::AttributeChanged(const FOnAttributeChangeData& Data) const
{
	OnAttributeChange.Broadcast(Data.Attribute,Data.NewValue,Data.OldValue);
}

