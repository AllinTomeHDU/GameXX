// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Status_MaxStamina.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Status_MaxStamina : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Status_MaxStamina();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition MaxStaminaBaseDef;
	FGameplayEffectAttributeCaptureDefinition MaxStaminaTempDef;

	FGameplayEffectAttributeCaptureDefinition VitalityDef;
};
