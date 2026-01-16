// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Status_HealthRe.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Status_HealthRe : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Status_HealthRe();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition HealthReBaseDef;
	FGameplayEffectAttributeCaptureDefinition HealthReTempDef;

	FGameplayEffectAttributeCaptureDefinition VitalityDef;
};
