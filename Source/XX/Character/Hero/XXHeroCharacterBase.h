// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "../XXCharacterBase.h"
#include "XXHeroCharacterBase.generated.h"


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
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilitySystemActorInfo();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* HeroMesh;

	UPROPERTY(EditAnywhere, Category = "GAS")
	class UXXPDA_AbilitiesBase* AbilitiesInputData;
};
