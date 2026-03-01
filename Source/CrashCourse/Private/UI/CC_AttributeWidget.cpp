// Copyright sakae


#include "UI/CC_AttributeWidget.h"

#include "AbilitySystem/CC_AttributeSet.h"

void UCC_AttributeWidget::OnAttributeChanged(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, const UCC_AttributeSet* AttributeSet)
{
	const float AttributeValue = Pair.Key.GetNumericValue(AttributeSet);
	const float MaxAttributeValue = Pair.Value.GetNumericValue(AttributeSet);
	
	BP_OnAttributeChanged(AttributeValue,MaxAttributeValue);

}

bool UCC_AttributeWidget::MatchAttribute(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	return Pair.Key == Attribute || Pair.Value == MaxAttribute;
}
