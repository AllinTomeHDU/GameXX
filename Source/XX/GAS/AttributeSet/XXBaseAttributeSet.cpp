// Copyright: Jichao Luo


#include "XXEnemyAttributeSet.h"
#include "Net/UnrealNetwork.h"


UXXBaseAttributeSet::UXXBaseAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(40.f);
	InitMaxMana(80.f);
}

void UXXBaseAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXBaseAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);

}

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
