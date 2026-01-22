// Copyright: Jichao Luo


#include "XXHeroAttributeSet.h"
#include "XX/GAS/XXGASBPLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"


UXXHeroAttributeSet::UXXHeroAttributeSet()
{
	
}

void UXXHeroAttributeSet::InitAttributes(const TArray<TSubclassOf<UGameplayEffect>>& EffectClassArr, float Level)
{
	auto ASC = GetOwningAbilitySystemComponentChecked();

	ASC->GetGameplayAttributeValueChangeDelegate(GetMaxStaminaAttribute())
		.AddUObject(this, &UXXHeroAttributeSet::OnMaxStaminaChanged);

	Super::InitAttributes(EffectClassArr, Level);
}

void UXXHeroAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
	}
	if (Attribute == GetFormAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxForm());
	}
}

void UXXHeroAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
	}
	if (Data.EvaluatedData.Attribute == GetFormAttribute())
	{
		SetForm(FMath::Clamp(GetForm(), 0.f, GetMaxForm()));
	}
}

void UXXHeroAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxStaminaBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, StaminaReBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxFormBase, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxStaminaTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, StaminaReTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxFormTemp, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, StaminaRe, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, Form, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxForm, COND_None, REPNOTIFY_Always);
}

void UXXHeroAttributeSet::OnMaxStaminaChanged(const FOnAttributeChangeData& Data)
{
	const float OldMax = Data.OldValue;
	const float NewMax = Data.NewValue;
	const float Delta = NewMax - OldMax;
	if (!FMath::IsNearlyZero(Delta))
	{
		float CurrentStamina = GetStamina();
		float NewStamina = CurrentStamina + Delta;
		SetStamina(FMath::Clamp(NewStamina, 0.f, NewMax));
	}
}

#pragma region Base Attributes
void UXXHeroAttributeSet::OnRep_MaxStaminaBase(const FGameplayAttributeData& OldMaxStaminaBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, MaxStaminaBase, OldMaxStaminaBase);
}

void UXXHeroAttributeSet::OnRep_StaminaReBase(const FGameplayAttributeData& OldStaminaReBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, StaminaReBase, OldStaminaReBase);
}

void UXXHeroAttributeSet::OnRep_MaxFormBase(const FGameplayAttributeData& OldMaxFormBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, MaxFormBase, OldMaxFormBase);
}
#pragma endregion

#pragma region Temp Attributes
void UXXHeroAttributeSet::OnRep_MaxStaminaTemp(const FGameplayAttributeData& OldMaxStaminaTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, MaxStaminaTemp, OldMaxStaminaTemp);
}

void UXXHeroAttributeSet::OnRep_StaminaReTemp(const FGameplayAttributeData& OldStaminaReTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, StaminaReTemp, OldStaminaReTemp);
}

void UXXHeroAttributeSet::OnRep_MaxFormTemp(const FGameplayAttributeData& OldMaxFormTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, MaxFormTemp, OldMaxFormTemp);
}
#pragma endregion

#pragma region Total Attributes
void UXXHeroAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, Stamina, OldStamina);
}

void UXXHeroAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, MaxStamina, OldMaxStamina);
}

void UXXHeroAttributeSet::OnRep_StaminaRe(const FGameplayAttributeData& OldStaminaRe) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, StaminaRe, OldStaminaRe);
}

void UXXHeroAttributeSet::OnRep_Form(const FGameplayAttributeData& OldForm) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, Form, OldForm);
}

void UXXHeroAttributeSet::OnRep_MaxForm(const FGameplayAttributeData& OldMaxForm) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, MaxForm, OldMaxForm);
}
#pragma endregion
