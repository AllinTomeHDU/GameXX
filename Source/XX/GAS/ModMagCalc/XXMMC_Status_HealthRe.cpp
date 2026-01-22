// Copyright: Jichao Luo


#include "XXMMC_Status_HealthRe.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Status_HealthRe::UXXMMC_Status_HealthRe()
{
	HealthReBaseDef.AttributeToCapture = UXXBaseAttributeSet::GetHealthReBaseAttribute();
	HealthReBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	HealthReBaseDef.bSnapshot = false;

	HealthReTempDef.AttributeToCapture = UXXBaseAttributeSet::GetHealthReTempAttribute();
	HealthReTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	HealthReTempDef.bSnapshot = false;

	VitalityDef.AttributeToCapture = UXXBaseAttributeSet::GetVitalityAttribute();
	VitalityDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VitalityDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(HealthReBaseDef);
	RelevantAttributesToCapture.Add(HealthReTempDef);
	RelevantAttributesToCapture.Add(VitalityDef);
}

float UXXMMC_Status_HealthRe::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float HealthReBaseValue = 0.f;
	GetCapturedAttributeMagnitude(HealthReBaseDef, Spec, EvaluateParameters, HealthReBaseValue);

	float HealthReTempValue = 0.f;
	GetCapturedAttributeMagnitude(HealthReTempDef, Spec, EvaluateParameters, HealthReTempValue);

	float VitalityValue = 0.f;
	GetCapturedAttributeMagnitude(VitalityDef, Spec, EvaluateParameters, VitalityValue);

	return HealthReBaseValue + HealthReTempValue + VitalityValue * 0.01;
}
