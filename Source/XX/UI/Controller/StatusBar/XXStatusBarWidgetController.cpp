// Copyright: Jichao Luo


#include "XXStatusBarWidgetController.h"
#include "XX/GAS/AbilitySystem/XXHeroAbilitySystemComponent.h"


void UXXStatusBarWidgetController::Init()
{
	Super::Init();
}

void UXXStatusBarWidgetController::BroadcastCurrentValues()
{
	OnHealthChanged.Broadcast(AttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AttributeSet->GetMaxMana());

	if (auto AS = Cast<UXXHeroAttributeSet>(AttributeSet))
	{
		OnStaminaChanged.Broadcast(AS->GetStamina());
		OnMaxStaminaChanged.Broadcast(AS->GetMaxStamina());
	}
}

void UXXStatusBarWidgetController::BindCallbacksToDependencies()
{
	AbilitySystem->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute())
		.AddUObject(this, &ThisClass::HealthChangedCallback);
	AbilitySystem->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &ThisClass::MaxHealthChangedCallback);

	AbilitySystem->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute())
		.AddUObject(this, &ThisClass::ManaChangedCallback);
	AbilitySystem->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute())
		.AddUObject(this, &ThisClass::MaxManaChangedCallback);

	if (auto AS = Cast<UXXHeroAttributeSet>(AttributeSet))
	{
		AbilitySystem->GetGameplayAttributeValueChangeDelegate(AS->GetStaminaAttribute())
			.AddUObject(this, &ThisClass::StaminaChangedCallback);
		AbilitySystem->GetGameplayAttributeValueChangeDelegate(AS->GetMaxStaminaAttribute())
			.AddUObject(this, &ThisClass::MaxStaminaChangedCallback);
	}
}

void UXXStatusBarWidgetController::HealthChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UXXStatusBarWidgetController::MaxHealthChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UXXStatusBarWidgetController::ManaChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UXXStatusBarWidgetController::MaxManaChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}

void UXXStatusBarWidgetController::StaminaChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnStaminaChanged.Broadcast(Data.NewValue);
}

void UXXStatusBarWidgetController::MaxStaminaChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnMaxStaminaChanged.Broadcast(Data.NewValue);
}

