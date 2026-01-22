// Copyright: Jichao Luo


#include "XXMMC_Status_ManaRe.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Status_ManaRe::UXXMMC_Status_ManaRe()
{
	ManaReBaseDef.AttributeToCapture = UXXBaseAttributeSet::GetManaReBaseAttribute();
	ManaReBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	ManaReBaseDef.bSnapshot = false;

	ManaReTempDef.AttributeToCapture = UXXBaseAttributeSet::GetManaReTempAttribute();
	ManaReTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	ManaReTempDef.bSnapshot = false;

	PrimalForceDef.AttributeToCapture = UXXBaseAttributeSet::GetPrimalForceAttribute();
	PrimalForceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	PrimalForceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(ManaReBaseDef);
	RelevantAttributesToCapture.Add(ManaReTempDef);
	RelevantAttributesToCapture.Add(PrimalForceDef);
}

float UXXMMC_Status_ManaRe::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float ManaReBaseValue = 0.f;
	GetCapturedAttributeMagnitude(ManaReBaseDef, Spec, EvaluateParameters, ManaReBaseValue);

	float ManaReTempValue = 0.f;
	GetCapturedAttributeMagnitude(ManaReTempDef, Spec, EvaluateParameters, ManaReTempValue);

	float PrimalForceValue = 0.f;
	GetCapturedAttributeMagnitude(PrimalForceDef, Spec, EvaluateParameters, PrimalForceValue);

	return ManaReBaseValue + ManaReTempValue + PrimalForceValue * 0.01f;
}
