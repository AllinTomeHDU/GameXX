// Copyright: Jichao Luo


#include "XXBaseAbilitySystemComponent.h"


void UXXBaseAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::OnEffectApplied);
}

void UXXBaseAbilitySystemComponent::OnEffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	//EffectSpec.GetAllAssetTags(TagContainer);
	//EffectSpec.GetAllGrantedTags(TagContainer);

	// 可以做Broadcast，让绑定的WidgetController执行具体逻辑
}
