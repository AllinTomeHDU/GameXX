// Copyright: Jichao Luo


#include "XXMMC_Primary_PrimalForce.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Primary_PrimalForce::UXXMMC_Primary_PrimalForce()
{
	PrimalForceBaseDef.AttributeToCapture = UXXHeroAttributeSet::GetPrimalForceBaseAttribute();
	PrimalForceBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	PrimalForceBaseDef.bSnapshot = false;

	PrimalForceTempDef.AttributeToCapture = UXXHeroAttributeSet::GetPrimalForceTempAttribute();
	PrimalForceTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	PrimalForceTempDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(PrimalForceBaseDef);
	RelevantAttributesToCapture.Add(PrimalForceTempDef);
}

float UXXMMC_Primary_PrimalForce::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float PrimalForceBaseValue = 0.f;
	GetCapturedAttributeMagnitude(PrimalForceBaseDef, Spec, EvaluateParameters, PrimalForceBaseValue);

	float PrimalForceTempValue = 0.f;
	GetCapturedAttributeMagnitude(PrimalForceTempDef, Spec, EvaluateParameters, PrimalForceTempValue);

	return PrimalForceBaseValue + PrimalForceTempValue;
}
