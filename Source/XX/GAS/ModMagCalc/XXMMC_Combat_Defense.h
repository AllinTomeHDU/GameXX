// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Combat_Defense.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Combat_Defense : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Combat_Defense();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition DefenseBaseDef;
	FGameplayEffectAttributeCaptureDefinition DefenseTempDef;

	FGameplayEffectAttributeCaptureDefinition VitalityDef;
};
