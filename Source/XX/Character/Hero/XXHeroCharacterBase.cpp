// Copyright: Jichao Luo


#include "XXHeroCharacterBase.h"
#include "XX/Player/XXHeroPlayerState.h"
#include "XX/Controller/XXHeroPlayerController.h"
#include "XX/GAS/AbilitySystem/XXHeroAbilitySystemComponent.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"
#include "XX/GAS/AbilitySystem/Data/XXPDA_AbilitiesBase.h"
#include "XX/UI/HUD/XXGameHUD.h"


AXXHeroCharacterBase::AXXHeroCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;

	HeroMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeroMeshComponent"));
	HeroMesh->SetupAttachment(GetMesh());
}

void AXXHeroCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (IsValid(AbilitiesInputData))
	{
		AbilitiesInputData->SetupInputComponent(this);
	}
}

void AXXHeroCharacterBase::PossessedBy(AController* NewController)
{
	// Server
	Super::PossessedBy(NewController);

	if (IsPlayerControlled())
	{
		InitAbilitySystemActorInfo();
		AbilitySystem->AddCharacterAbilities(InitAbilityClassArr);
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
	AttributeSet->InitAttributes(InitEffectClassArr);
}