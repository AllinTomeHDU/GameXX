// Copyright: Jichao Luo


#include "XXMMC_Primary_Vitality.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Primary_Vitality::UXXMMC_Primary_Vitality()
{
	VitalityBaseDef.AttributeToCapture = UXXHeroAttributeSet::GetVitalityBaseAttribute();
	VitalityBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VitalityBaseDef.bSnapshot = false;

	VitalityTempDef.AttributeToCapture = UXXHeroAttributeSet::GetVitalityTempAttribute();
	VitalityTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VitalityTempDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(VitalityBaseDef);
	RelevantAttributesToCapture.Add(VitalityTempDef);
}

float UXXMMC_Primary_Vitality::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float VitalityBaseValue = 0.f;
	GetCapturedAttributeMagnitude(VitalityBaseDef, Spec, EvaluateParameters, VitalityBaseValue);

	float VitalityTempValue = 0.f;
	GetCapturedAttributeMagnitude(VitalityTempDef, Spec, EvaluateParameters, VitalityTempValue);

	return VitalityBaseValue + VitalityTempValue;
}
