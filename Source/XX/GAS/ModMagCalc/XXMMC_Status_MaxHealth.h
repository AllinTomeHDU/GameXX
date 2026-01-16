// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Status_MaxHealth.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Status_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Status_MaxHealth();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition MaxHealthBaseDef;
	FGameplayEffectAttributeCaptureDefinition MaxHealthTempDef;

};
