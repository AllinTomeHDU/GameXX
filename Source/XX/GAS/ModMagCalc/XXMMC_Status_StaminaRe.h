// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Status_StaminaRe.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Status_StaminaRe : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Status_StaminaRe();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition StaminaReBaseDef;
	FGameplayEffectAttributeCaptureDefinition StaminaReTempDef;

	FGameplayEffectAttributeCaptureDefinition VitalityDef;
};
