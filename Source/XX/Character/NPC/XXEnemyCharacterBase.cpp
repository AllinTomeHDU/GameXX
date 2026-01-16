// Copyright: Jichao Luo


#include "XXEnemyCharacterBase.h"
#include "XX/GAS/AbilitySystem/XXEnemyAbilitySystemComponent.h"
#include "XX/GAS/AttributeSet/XXEnemyAttributeSet.h"


AXXEnemyCharacterBase::AXXEnemyCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AbilitySystem = CreateDefaultSubobject<UXXEnemyAbilitySystemComponent>(TEXT("EnemyAbilitySystem"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UXXEnemyAttributeSet>(TEXT("EnemyAttributeSet"));
}

void AXXEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystem->InitAbilityActorInfo(this, this);
	AttributeSet->InitAttributes(InitEffectClassArr);
}
