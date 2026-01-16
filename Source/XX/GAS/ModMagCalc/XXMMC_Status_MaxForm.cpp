// Copyright: Jichao Luo


#include "XXMMC_Status_MaxForm.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Status_MaxForm::UXXMMC_Status_MaxForm()
{
	MaxFormBaseDef.AttributeToCapture = UXXHeroAttributeSet::GetMaxFormBaseAttribute();
	MaxFormBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxFormBaseDef.bSnapshot = false;

	MaxFormTempDef.AttributeToCapture = UXXHeroAttributeSet::GetMaxFormTempAttribute();
	MaxFormTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxFormTempDef.bSnapshot = false;

	VitalityDef.AttributeToCapture = UXXHeroAttributeSet::GetVitalityAttribute();
	VitalityDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VitalityDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(MaxFormBaseDef);
	RelevantAttributesToCapture.Add(MaxFormTempDef);
	RelevantAttributesToCapture.Add(VitalityDef);
}

float UXXMMC_Status_MaxForm::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float MaxFormBaseValue = 0.f;
	GetCapturedAttributeMagnitude(MaxFormBaseDef, Spec, EvaluateParameters, MaxFormBaseValue);

	float MaxFormTempValue = 0.f;
	GetCapturedAttributeMagnitude(MaxFormTempDef, Spec, EvaluateParameters, MaxFormTempValue);

	float VitalityValue = 0.f;
	GetCapturedAttributeMagnitude(VitalityDef, Spec, EvaluateParameters, VitalityValue);

	// 势是分阶段有上限的



	return MaxFormBaseValue + MaxFormTempValue;
}
