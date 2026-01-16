// Copyright: Jichao Luo


#include "XXHeroAttributeSet.h"
#include "XX/GAS/XXGASBPLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"


UXXHeroAttributeSet::UXXHeroAttributeSet()
{
	
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
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, VitalityBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, PrimalForceBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, InsightBase, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxStaminaTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, StaminaReTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxFormTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, VitalityTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, PrimalForceTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, InsightTemp, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, StaminaRe, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, Form, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxForm, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, Vitality, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, PrimalForce, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, Insight, COND_None, REPNOTIFY_Always);
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

void UXXHeroAttributeSet::OnRep_VitalityBase(const FGameplayAttributeData& OldVitalityBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, VitalityBase, OldVitalityBase);
}

void UXXHeroAttributeSet::OnRep_PrimalForceBase(const FGameplayAttributeData& OldPrimalForceBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, PrimalForceBase, OldPrimalForceBase);
}

void UXXHeroAttributeSet::OnRep_InsightBase(const FGameplayAttributeData& OldInsightBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, InsightBase, OldInsightBase);
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

void UXXHeroAttributeSet::OnRep_VitalityTemp(const FGameplayAttributeData& OldVitalityTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, VitalityTemp, OldVitalityTemp);
}

void UXXHeroAttributeSet::OnRep_PrimalForceTemp(const FGameplayAttributeData& OldPrimalForceTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, PrimalForceTemp, OldPrimalForceTemp);
}

void UXXHeroAttributeSet::OnRep_InsightTemp(const FGameplayAttributeData& OldInsightTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, InsightTemp, OldInsightTemp);
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

void UXXHeroAttributeSet::OnRep_Vitality(const FGameplayAttributeData& OldVitality) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, Vitality, OldVitality);
}

void UXXHeroAttributeSet::OnRep_PrimalForce(const FGameplayAttributeData& OldPrimalForce) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, PrimalForce, OldPrimalForce);
}

void UXXHeroAttributeSet::OnRep_Insight(const FGameplayAttributeData& OldInsight) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, Insight, OldInsight);
}
#pragma endregion
