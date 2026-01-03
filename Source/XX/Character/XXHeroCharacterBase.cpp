// Copyright: Jichao Luo


#include "XXHeroCharacterBase.h"


AXXHeroCharacterBase::AXXHeroCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;

	HeroMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeroMeshComponent"));
	HeroMesh->SetupAttachment(GetMesh());
}
