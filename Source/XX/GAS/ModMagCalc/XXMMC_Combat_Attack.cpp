// Copyright: Jichao Luo


#include "XXMMC_Combat_Attack.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Combat_Attack::UXXMMC_Combat_Attack()
{
	AttackBaseDef.AttributeToCapture = UXXHeroAttributeSet::GetAttackBaseAttribute();
	AttackBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	AttackBaseDef.bSnapshot = false;

	AttackTempDef.AttributeToCapture = UXXHeroAttributeSet::GetAttackTempAttribute();
	AttackTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	AttackTempDef.bSnapshot = false;

	VitalityDef.AttributeToCapture = UXXHeroAttributeSet::GetVitalityAttribute();
	VitalityDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VitalityDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(AttackBaseDef);
	RelevantAttributesToCapture.Add(AttackTempDef);
	RelevantAttributesToCapture.Add(VitalityDef);
}

float UXXMMC_Combat_Attack::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float AttackBaseValue = 0.f;
	GetCapturedAttributeMagnitude(AttackBaseDef, Spec, EvaluateParameters, AttackBaseValue);

	float AttackTempValue = 0.f;
	GetCapturedAttributeMagnitude(AttackTempDef, Spec, EvaluateParameters, AttackTempValue);

	float VitalityValue = 0.f;
	GetCapturedAttributeMagnitude(VitalityDef, Spec, EvaluateParameters, VitalityValue);

	return AttackBaseValue + AttackTempValue + VitalityValue;
}
