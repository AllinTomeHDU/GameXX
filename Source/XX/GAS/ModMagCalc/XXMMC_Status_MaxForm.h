// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Status_MaxForm.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Status_MaxForm : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Status_MaxForm();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition MaxFormBaseDef;
	FGameplayEffectAttributeCaptureDefinition MaxFormTempDef;

	FGameplayEffectAttributeCaptureDefinition VitalityDef;
};
