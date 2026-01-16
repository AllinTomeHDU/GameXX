// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Status_MaxMana.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Status_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Status_MaxMana();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition MaxManaBaseDef;
	FGameplayEffectAttributeCaptureDefinition MaxManaTempDef;

	FGameplayEffectAttributeCaptureDefinition PrimalForceDef;
};
