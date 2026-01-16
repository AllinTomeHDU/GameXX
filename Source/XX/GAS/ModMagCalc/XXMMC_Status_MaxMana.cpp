// Copyright: Jichao Luo


#include "XXMMC_Status_MaxMana.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Status_MaxMana::UXXMMC_Status_MaxMana()
{
	MaxManaBaseDef.AttributeToCapture = UXXBaseAttributeSet::GetMaxManaBaseAttribute();
	MaxManaBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxManaBaseDef.bSnapshot = false;

	MaxManaTempDef.AttributeToCapture = UXXBaseAttributeSet::GetMaxManaTempAttribute();
	MaxManaTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxManaTempDef.bSnapshot = false;

	PrimalForceDef.AttributeToCapture = UXXHeroAttributeSet::GetPrimalForceAttribute();
	PrimalForceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	PrimalForceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(MaxManaBaseDef);
	RelevantAttributesToCapture.Add(MaxManaTempDef);
	RelevantAttributesToCapture.Add(PrimalForceDef);
}

float UXXMMC_Status_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float MaxManaBaseValue = 0.f;
	GetCapturedAttributeMagnitude(MaxManaBaseDef, Spec, EvaluateParameters, MaxManaBaseValue);

	float MaxManaTempValue = 0.f;
	GetCapturedAttributeMagnitude(MaxManaTempDef, Spec, EvaluateParameters, MaxManaTempValue);

	float PrimalForceValue = 0.f;
	GetCapturedAttributeMagnitude(PrimalForceDef, Spec, EvaluateParameters, PrimalForceValue);

	return MaxManaBaseValue + MaxManaTempValue + PrimalForceValue;
}
