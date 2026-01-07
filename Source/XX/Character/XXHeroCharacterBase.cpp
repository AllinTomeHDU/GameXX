// Copyright: Jichao Luo


#include "XXHeroCharacterBase.h"
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"


AXXHeroCharacterBase::AXXHeroCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;

	HeroMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeroMeshComponent"));
	HeroMesh->SetupAttachment(GetMesh());

	HeadTopWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	HeadTopWidget->SetupAttachment(HeroMesh);
	HeadTopWidget->SetRelativeLocation(FVector(0.f, 0.f, GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 2));
	HeadTopWidget->SetWidgetSpace(EWidgetSpace::Screen);
}
