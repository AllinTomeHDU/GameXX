// Copyright: Jichao Luo


#include "XXMMC_Status_HealthRe.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Status_HealthRe::UXXMMC_Status_HealthRe()
{
	HealthReBaseDef.AttributeToCapture = UXXHeroAttributeSet::GetHealthReBaseAttribute();
	HealthReBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	HealthReBaseDef.bSnapshot = false;

	HealthReTempDef.AttributeToCapture = UXXHeroAttributeSet::GetHealthReTempAttribute();
	HealthReTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	HealthReTempDef.bSnapshot = false;

	VitalityDef.AttributeToCapture = UXXHeroAttributeSet::GetVitalityAttribute();
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

	// 体魄值对体力条的提升收益递减
	const float Scale = 100.f;			// 控制饱和点，体魄值越接近Scale，收益越趋缓
	const float VitalityFactor = 5.f;	// 决定体魄对体力的影响度
	float VitalityBonus = VitalityFactor * (VitalityValue / (VitalityValue + Scale));

	// 带上限的平滑饱和曲线，装备效果的回血效果加成为百分号数
	// FinalRegen = BaseRegen + (MaxRegen - BaseRegen) * (Bonus / (Bonus+k))
	float MaxRegen = 0.25f;
	float Bonus = HealthReTempValue + VitalityBonus;
	return HealthReBaseValue + (MaxRegen - HealthReBaseValue) * (Bonus / (Bonus + 2.f));
}
