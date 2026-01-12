// Copyright: Jichao Luo


#include "XXEnemyAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"


UXXBaseAttributeSet::UXXBaseAttributeSet()
{
	// Hard Code，最好是根据资产表配置，每个角色的初始化数值不一样
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(40.f);
	InitMaxMana(80.f);
}

void UXXBaseAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UXXBaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// 在属性改变后根据，可执行一些具体的逻辑，通过Data可得到触发Effect的Source和Target信息

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
}

void UXXBaseAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, HealthBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, MaxHealthBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, ManaBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, MaxManaBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, AttackBase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, DefenseBase, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, HealthTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, MaxHealthTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, ManaTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, MaxManaTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, AttackTemp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, DefenseTemp, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, Attack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, Defense, COND_None, REPNOTIFY_Always);
}

#pragma region Base Attributes
void UXXBaseAttributeSet::OnRep_HealthBase(const FGameplayAttributeData& OldHealthBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, HealthBase, OldHealthBase);
}

void UXXBaseAttributeSet::OnRep_MaxHealthBase(const FGameplayAttributeData& OldMaxHealthBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, MaxHealthBase, OldMaxHealthBase);
}

void UXXBaseAttributeSet::OnRep_ManaBase(const FGameplayAttributeData& OldManaBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, ManaBase, OldManaBase);
}

void UXXBaseAttributeSet::OnRep_MaxManaBase(const FGameplayAttributeData& OldMaxManaBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, MaxManaBase, OldMaxManaBase);
}

void UXXBaseAttributeSet::OnRep_AttackBase(const FGameplayAttributeData& OldAttackBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, AttackBase, OldAttackBase);
}

void UXXBaseAttributeSet::OnRep_DefenseBase(const FGameplayAttributeData& OldDefenseBase) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, DefenseBase, OldDefenseBase);
}
#pragma endregion

#pragma region Temp Attributes
void UXXBaseAttributeSet::OnRep_HealthTemp(const FGameplayAttributeData& OldHealthTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, HealthTemp, OldHealthTemp);
}

void UXXBaseAttributeSet::OnRep_MaxHealthTemp(const FGameplayAttributeData& OldMaxHealthTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, MaxHealthTemp, OldMaxHealthTemp);
}

void UXXBaseAttributeSet::OnRep_ManaTemp(const FGameplayAttributeData& OldManaTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, ManaTemp, OldManaTemp);
}

void UXXBaseAttributeSet::OnRep_MaxManaTemp(const FGameplayAttributeData& OldMaxManaTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, MaxManaTemp, OldMaxManaTemp);
}

void UXXBaseAttributeSet::OnRep_AttackTemp(const FGameplayAttributeData& OldAttackTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, AttackTemp, OldAttackTemp);
}

void UXXBaseAttributeSet::OnRep_DefenseTemp(const FGameplayAttributeData& OldDefenseTemp) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, DefenseTemp, OldDefenseTemp);
}
#pragma endregion

#pragma region Total Attributes
void UXXBaseAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, Health, OldHealth);
}

void UXXBaseAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, MaxHealth, OldMaxHealth);
}

void UXXBaseAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, Mana, OldMana);
}

void UXXBaseAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, MaxMana, OldMaxMana);
}

void UXXBaseAttributeSet::OnRep_Attack(const FGameplayAttributeData& OldAttack) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, Attack, OldAttack);
}

void UXXBaseAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldDefense) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXBaseAttributeSet, Defense, OldDefense);
}
#pragma endregion