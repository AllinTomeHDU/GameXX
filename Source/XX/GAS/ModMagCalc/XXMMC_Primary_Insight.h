// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "XXMMC_Primary_Insight.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXMMC_Primary_Insight : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UXXMMC_Primary_Insight();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition InsightBaseDef;
	FGameplayEffectAttributeCaptureDefinition InsightTempDef;

};
