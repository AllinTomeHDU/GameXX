// Copyright: Jichao Luo


#include "XXBaseAbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"


void UXXBaseAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::OnEffectApplied);
}

void UXXBaseAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& AbilitiesClass)
{
	if (GetOwnerRole() != ENetRole::ROLE_Authority) return;

	// 注册Abilities
	for (auto AbilityClass : AbilitiesClass)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		FGameplayAbilitySpecHandle AbilityHandle = GiveAbility(AbilitySpec);
	}
}

void UXXBaseAbilitySystemComponent::OnEffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	//EffectSpec.GetAllAssetTags(TagContainer);
	//EffectSpec.GetAllGrantedTags(TagContainer);

	// 可以做Broadcast，让绑定的WidgetController执行具体逻辑
}
