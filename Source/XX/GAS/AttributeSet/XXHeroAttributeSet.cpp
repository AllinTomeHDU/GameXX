// Copyright: Jichao Luo


#include "XXHeroAttributeSet.h"
#include "Net/UnrealNetwork.h"


UXXHeroAttributeSet::UXXHeroAttributeSet()
{
	InitStamina(50.f);
	InitMaxStamina(100.f);
}

void UXXHeroAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXXHeroAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
}

void UXXHeroAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, Stamina, OldStamina);
}

void UXXHeroAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXXHeroAttributeSet, MaxStamina, OldMaxStamina);
}
