// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/3C/Character/MMAlsCharacter.h"
#include "XXHeroCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class XX_API AXXHeroCharacterBase : public AMMAlsCharacter
{
	GENERATED_BODY()
	
public:
	AXXHeroCharacterBase(const FObjectInitializer& ObjectInitializer);
	
protected:


private:
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* HeroMesh;
};
