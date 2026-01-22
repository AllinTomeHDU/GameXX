// Copyright: Jichao Luo


#include "XXCharacterBase.h"
#include "XX/GAS/XXGASBPLibrary.h"
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"
#include "Net/UnrealNetwork.h"


AXXCharacterBase::AXXCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = false;

	HeadTopWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	HeadTopWidget->SetupAttachment(GetMesh());
	HeadTopWidget->SetRelativeLocation(FVector(0.f, 0.f, GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 2));
	HeadTopWidget->SetWidgetSpace(EWidgetSpace::Screen);
}

void AXXCharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AXXCharacterBase, CharacterLevel);
}

void AXXCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		LevelUp(CharacterLevel);
	}

	// 在复活时调用，重置状态
	//checkf(ResetStatusEffectClass, TEXT("ResetStatusEffectClass is nullptr"));
	//FActiveGameplayEffectHandle EffectHandle;
	//UXXGASBPLibrary::ApplyEffectToTarget(EffectHandle, this, this, ResetStatusEffectClass, 1);
}

void AXXCharacterBase::LevelUp(int32 Number)
{
	Server_LevelUp(Number);
}

void AXXCharacterBase::Server_LevelUp_Implementation(int32 Number)
{
	OnLevelUp(CharacterLevel);
	CharacterLevel += Number;
	if (GrowthAttributesEffectClass)
	{
		FActiveGameplayEffectHandle EffectHandle;
		UXXGASBPLibrary::ApplyEffectToTarget(EffectHandle, this, this, GrowthAttributesEffectClass, Number);
	}
}

void AXXCharacterBase::OnRep_CharacterLevel(int32 PrevLevel)
{
	OnLevelUp(PrevLevel);
}

void AXXCharacterBase::OnLevelUp(int32 PrevLevel)
{
	// 升级时涉及到一些UI、特效的播放
}
