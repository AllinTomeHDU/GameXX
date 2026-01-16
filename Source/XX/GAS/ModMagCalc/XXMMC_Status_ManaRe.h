// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Status_ManaRe.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Status_ManaRe : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Status_ManaRe();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition ManaReBaseDef;
	FGameplayEffectAttributeCaptureDefinition ManaReTempDef;

	FGameplayEffectAttributeCaptureDefinition PrimalForceDef;
};
