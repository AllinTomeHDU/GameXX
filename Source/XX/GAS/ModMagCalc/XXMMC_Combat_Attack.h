// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Combat_Attack.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Combat_Attack : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Combat_Attack();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition AttackBaseDef;
	FGameplayEffectAttributeCaptureDefinition AttackTempDef;

	FGameplayEffectAttributeCaptureDefinition VitalityDef;
};
