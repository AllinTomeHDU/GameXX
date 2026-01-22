// Copyright: Jichao Luo


#include "XXEnemyCharacterBase.h"
#include "XX/GAS/AbilitySystem/XXEnemyAbilitySystemComponent.h"
#include "XX/GAS/AttributeSet/XXEnemyAttributeSet.h"
#include "XX/UI/Widget/XXUserWidgetBase.h"
#include "Components/WidgetComponent.h"


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
	AbilitySystem->AddCharacterAbilities(InitAbilityClassArr);
	AttributeSet->InitAttributes(InitEffectClassArr);

	InitHeadTopWidget();
}

void AXXEnemyCharacterBase::InitHeadTopWidget()
{
	if (auto Widget = Cast<UXXUserWidgetBase>(HeadTopWidget->GetUserWidgetObject()))
	{
		Widget->SetWidgetController(this);
	}

	AbilitySystem->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);
	AbilitySystem->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	OnHealthChanged.Broadcast(AttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AttributeSet->GetMaxHealth());
}
