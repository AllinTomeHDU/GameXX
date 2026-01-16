// Copyright: Jichao Luo


#include "XXMMC_Status_MaxHealth.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Status_MaxHealth::UXXMMC_Status_MaxHealth()
{
	MaxHealthBaseDef.AttributeToCapture = UXXBaseAttributeSet::GetMaxHealthBaseAttribute();
	MaxHealthBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxHealthBaseDef.bSnapshot = false;

	MaxHealthTempDef.AttributeToCapture = UXXBaseAttributeSet::GetMaxHealthTempAttribute();
	MaxHealthTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxHealthTempDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(MaxHealthBaseDef);
	RelevantAttributesToCapture.Add(MaxHealthTempDef);
}

float UXXMMC_Status_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float MaxHealthBaseValue = 0.f;
	GetCapturedAttributeMagnitude(MaxHealthBaseDef, Spec, EvaluateParameters, MaxHealthBaseValue);

	float MaxHealthTempValue = 0.f;
	GetCapturedAttributeMagnitude(MaxHealthTempDef, Spec, EvaluateParameters, MaxHealthTempValue);

	return MaxHealthBaseValue + MaxHealthTempValue;
}
