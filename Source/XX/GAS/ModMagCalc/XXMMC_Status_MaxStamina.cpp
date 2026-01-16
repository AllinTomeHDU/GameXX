// Copyright: Jichao Luo


#include "XXMMC_Status_MaxStamina.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"


UXXMMC_Status_MaxStamina::UXXMMC_Status_MaxStamina()
{
	MaxStaminaBaseDef.AttributeToCapture = UXXHeroAttributeSet::GetMaxStaminaBaseAttribute();
	MaxStaminaBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxStaminaBaseDef.bSnapshot = false;

	MaxStaminaTempDef.AttributeToCapture = UXXHeroAttributeSet::GetMaxStaminaTempAttribute();
	MaxStaminaTempDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxStaminaTempDef.bSnapshot = false;

	VitalityDef.AttributeToCapture = UXXHeroAttributeSet::GetVitalityAttribute();
	VitalityDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VitalityDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(MaxStaminaBaseDef);
	RelevantAttributesToCapture.Add(MaxStaminaTempDef);
	RelevantAttributesToCapture.Add(VitalityDef);
}

float UXXMMC_Status_MaxStamina::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float MaxStaminaBaseValue = 0.f;
	GetCapturedAttributeMagnitude(MaxStaminaBaseDef, Spec, EvaluateParameters, MaxStaminaBaseValue);

	float MaxStaminaTempValue = 0.f;
	GetCapturedAttributeMagnitude(MaxStaminaTempDef, Spec, EvaluateParameters, MaxStaminaTempValue);

	float VitalityValue = 0.f;
	GetCapturedAttributeMagnitude(VitalityDef, Spec, EvaluateParameters, VitalityValue);

	// 体魄值对体力条的提升收益递减
	const float Scale = 100.f;			// 控制饱和点，体魄值越接近Scale，收益越趋缓
	const float VitalityFactor = 100.f;	// 决定体魄对体力的影响度
	float VitalityBonus = VitalityFactor * (VitalityValue / (VitalityValue + Scale));

	return MaxStaminaBaseValue + MaxStaminaTempValue + VitalityBonus;
}
