// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "../XXCharacterBase.h"
#include "XXHeroCharacterBase.generated.h"

class UWidgetComponent;


/**
 * 
 */
UCLASS()
class XX_API AXXHeroCharacterBase : public AXXCharacterBase
{
	GENERATED_BODY()
	
public:
	AXXHeroCharacterBase(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilitySystemActorInfo();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Multiplayer Room", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* HeroMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Multiplayer Room", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* HeadTopWidget;

};
