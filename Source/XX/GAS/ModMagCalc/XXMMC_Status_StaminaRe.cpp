// Copyright: Jichao Luo


#include "XXMMC_Status_StaminaRe.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Status_StaminaRe::UXXMMC_Status_StaminaRe()
{
	StaminaReBaseDef.AttributeToCapture = UXXHeroAttributeSet::GetStaminaReBaseAttribute();
	StaminaReBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	StaminaReBaseDef.bSnapshot = false;

	StaminaReTempDef.AttributeToCapture = UXXHeroAttributeSet::GetStaminaReTempAttribute();
	StaminaReTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	StaminaReTempDef.bSnapshot = false;

	VitalityDef.AttributeToCapture = UXXHeroAttributeSet::GetVitalityAttribute();
	VitalityDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VitalityDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(StaminaReBaseDef);
	RelevantAttributesToCapture.Add(StaminaReTempDef);
	RelevantAttributesToCapture.Add(VitalityDef);
}

float UXXMMC_Status_StaminaRe::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float StaminaReBaseValue = 0.f;
	GetCapturedAttributeMagnitude(StaminaReBaseDef, Spec, EvaluateParameters, StaminaReBaseValue);

	float StaminaReTempValue = 0.f;
	GetCapturedAttributeMagnitude(StaminaReTempDef, Spec, EvaluateParameters, StaminaReTempValue);

	float VitalityValue = 0.f;
	GetCapturedAttributeMagnitude(VitalityDef, Spec, EvaluateParameters, VitalityValue);

	// 体魄值对体力条的提升收益递减
	const float Scale = 100.f;			// 控制饱和点，体魄值越接近Scale，收益越趋缓
	const float VitalityFactor = 5.f;	// 决定体魄对体力的影响度
	float VitalityBonus = VitalityFactor * (VitalityValue / (VitalityValue + Scale));

	// 带上限的平滑饱和曲线，体力回复效果加成为百分号数
	// FinalRegen = BaseRegen + (MaxRegen - BaseRegen) * (Bonus / (Bonus+k))
	float MaxRegen = 50.f;	// 当前的体力条最大值是200，设置回复速度最大为50
	float Bonus = StaminaReTempValue + VitalityBonus;
	return StaminaReBaseValue + (MaxRegen - StaminaReBaseValue) * (Bonus / (Bonus + 5.f));
}
