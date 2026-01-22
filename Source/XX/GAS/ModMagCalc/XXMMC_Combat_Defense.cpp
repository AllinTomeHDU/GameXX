// Copyright: Jichao Luo


#include "XXMMC_Combat_Defense.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Combat_Defense::UXXMMC_Combat_Defense()
{
	DefenseBaseDef.AttributeToCapture = UXXBaseAttributeSet::GetDefenseBaseAttribute();
	DefenseBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	DefenseBaseDef.bSnapshot = false;

	DefenseTempDef.AttributeToCapture = UXXBaseAttributeSet::GetDefenseTempAttribute();
	DefenseTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	DefenseTempDef.bSnapshot = false;

	VitalityDef.AttributeToCapture = UXXBaseAttributeSet::GetVitalityAttribute();
	VitalityDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VitalityDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(DefenseBaseDef);
	RelevantAttributesToCapture.Add(DefenseTempDef);
	RelevantAttributesToCapture.Add(VitalityDef);
}

float UXXMMC_Combat_Defense::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float DefenseBaseValue = 0.f;
	GetCapturedAttributeMagnitude(DefenseBaseDef, Spec, EvaluateParameters, DefenseBaseValue);

	float DefenseTempValue = 0.f;
	GetCapturedAttributeMagnitude(DefenseTempDef, Spec, EvaluateParameters, DefenseTempValue);

	float VitalityValue = 0.f;
	GetCapturedAttributeMagnitude(VitalityDef, Spec, EvaluateParameters, VitalityValue);

	return DefenseBaseValue + DefenseTempValue + VitalityValue * 0.1f;
}
