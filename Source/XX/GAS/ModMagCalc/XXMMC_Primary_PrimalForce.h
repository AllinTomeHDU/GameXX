// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Primary_PrimalForce.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Primary_PrimalForce : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Primary_PrimalForce();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition PrimalForceBaseDef;
	FGameplayEffectAttributeCaptureDefinition PrimalForceTempDef;

};
