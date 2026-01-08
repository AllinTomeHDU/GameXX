// Copyright: Jichao Luo


#include "XXNoPlayerCharacterBase.h"


AXXNoPlayerCharacterBase::AXXNoPlayerCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

}

void AXXNoPlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
