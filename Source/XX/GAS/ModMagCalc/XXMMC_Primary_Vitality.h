// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Primary_Vitality.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Primary_Vitality : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Primary_Vitality();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition VitalityBaseDef;
	FGameplayEffectAttributeCaptureDefinition VitalityTempDef;

};
