// Copyright: Jichao Luo


#include "XXHeroPlayerState.h"
#include "XX/GAS/AbilitySystem/XXHeroAbilitySystemComponent.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


AXXHeroPlayerState::AXXHeroPlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystem = CreateDefaultSubobject<UXXHeroAbilitySystemComponent>(TEXT("HeroAbilitySystem"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UXXHeroAttributeSet>(TEXT("HeroAttributeSet"));
}
