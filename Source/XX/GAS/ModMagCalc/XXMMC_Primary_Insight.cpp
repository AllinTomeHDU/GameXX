// Copyright: Jichao Luo


#include "XXMMC_Primary_Insight.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Primary_Insight::UXXMMC_Primary_Insight()
{
	InsightBaseDef.AttributeToCapture = UXXHeroAttributeSet::GetInsightBaseAttribute();
	InsightBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	InsightBaseDef.bSnapshot = false;

	InsightTempDef.AttributeToCapture = UXXHeroAttributeSet::GetInsightTempAttribute();
	InsightTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	InsightTempDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(InsightBaseDef);
	RelevantAttributesToCapture.Add(InsightTempDef);
}

float UXXMMC_Primary_Insight::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float InsightBaseValue = 0.f;
	GetCapturedAttributeMagnitude(InsightBaseDef, Spec, EvaluateParameters, InsightBaseValue);

	float InsightTempValue = 0.f;
	GetCapturedAttributeMagnitude(InsightTempDef, Spec, EvaluateParameters, InsightTempValue);

	return InsightBaseValue + InsightTempValue;
}
