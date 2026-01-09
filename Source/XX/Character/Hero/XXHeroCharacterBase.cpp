// Copyright: Jichao Luo


#include "XXHeroCharacterBase.h"
#include "XX/Player/XXHeroPlayerState.h"
#include "XX/Controller/XXHeroPlayerController.h"
#include "XX/GAS/AbilitySystem/XXHeroAbilitySystemComponent.h"
#include "XX/UI/HUD/XXGameHUD.h"
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"


AXXHeroCharacterBase::AXXHeroCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;

	HeroMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeroMeshComponent"));
	HeroMesh->SetupAttachment(GetMesh());

	HeadTopWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	HeadTopWidget->SetupAttachment(HeroMesh);
	HeadTopWidget->SetRelativeLocation(FVector(0.f, 0.f, GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 2));
	HeadTopWidget->SetWidgetSpace(EWidgetSpace::Screen);
}

void AXXHeroCharacterBase::PossessedBy(AController* NewController)
{
	// Server
	Super::PossessedBy(NewController);

	if (IsPlayerControlled())
	{
		InitAbilitySystemActorInfo();
	}
}

void AXXHeroCharacterBase::OnRep_PlayerState()
{
	// Client
	Super::OnRep_PlayerState();

	InitAbilitySystemActorInfo();
}

void AXXHeroCharacterBase::InitAbilitySystemActorInfo()
{
	auto PS = Cast<AXXHeroPlayerState>(GetPlayerState());
	check(PS);

	PS->GetBaseAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
	AbilitySystem = PS->GetBaseAbilitySystemComponent();
	AttributeSet = PS->GetBaseAttributeSet();
	check(AbilitySystem && AttributeSet);

	if (auto PC = Cast<AXXHeroPlayerController>(Controller))
	{
		if (auto GameHUD = Cast<AXXGameHUD>(PC->GetHUD()))
		{
			GameHUD->InitOverlay();
		}
	}
}