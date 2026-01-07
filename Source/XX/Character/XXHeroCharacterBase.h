// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/3C/Character/MMAlsCharacter.h"
#include "XXHeroCharacterBase.generated.h"

class UWidgetComponent;

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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Multiplayer Room", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* HeroMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Multiplayer Room", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* HeadTopWidget;
};
