// Copyright: Jichao Luo

#pragma once

#include "XXBaseAttributeSet.h"
#include "XXHeroAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXHeroAttributeSet : public UXXBaseAttributeSet
{
	GENERATED_BODY()

public:
	UXXHeroAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

public:
	/**
	* 基本属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStaminaBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData MaxStaminaBase;  // 最大体力值
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, MaxStaminaBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StaminaReBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData StaminaReBase;	// 体力回复
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, StaminaReBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxFormBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData MaxFormBase;  // 最大势
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, MaxFormBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VitalityBase, Category = "BaseAttributes|Primary")
	FGameplayAttributeData VitalityBase;	// 体魄
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, VitalityBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PrimalForceBase, Category = "BaseAttributes|Primary")
	FGameplayAttributeData PrimalForceBase;	// 本源
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, PrimalForceBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_InsightBase, Category = "BaseAttributes|Primary")
	FGameplayAttributeData InsightBase;	// 悟性
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, InsightBase);

	/**
	* 附加属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStaminaTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData MaxStaminaTemp;  // 最大体力值
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, MaxStaminaTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StaminaReTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData StaminaReTemp;	// 体力回复
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, StaminaReTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxFormTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData MaxFormTemp;  // 最大势
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, MaxFormTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VitalityTemp, Category = "TempAttributes|Primary")
	FGameplayAttributeData VitalityTemp;	// 体魄
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, VitalityTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PrimalForceTemp, Category = "TempAttributes|Primary")
	FGameplayAttributeData PrimalForceTemp;	// 本源
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, PrimalForceTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_InsightTemp, Category = "TempAttributes|Primary")
	FGameplayAttributeData InsightTemp;	// 悟性
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, InsightTemp);

	/**
	* 最终属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "TotalAttributes|Status")
	FGameplayAttributeData Stamina;	// 体力值：直接进行加减计算的当前值
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "TotalAttributes|Status")
	FGameplayAttributeData MaxStamina;  // 最大体力值 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, MaxStamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StaminaRe, Category = "TotalAttributes|Status")
	FGameplayAttributeData StaminaRe;	// 体力回复 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, StaminaRe);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Form, Category = "TotalAttributes|Status")
	FGameplayAttributeData Form;	// 势：直接进行加减计算的当前值
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, Form);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxForm, Category = "TotalAttributes|Status")
	FGameplayAttributeData MaxForm;  // 最大势 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, MaxForm);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vitality, Category = "TotalAttributes|Primary")
	FGameplayAttributeData Vitality;	// 体魄 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, Vitality);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PrimalForce, Category = "TotalAttributes|Primary")
	FGameplayAttributeData PrimalForce;	// 本源 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, PrimalForce);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Insight, Category = "TotalAttributes|Primary")
	FGameplayAttributeData Insight;	// 悟性 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, Insight);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	/**
	* 基本属性值
	*/
	UFUNCTION()
	void OnRep_MaxStaminaBase(const FGameplayAttributeData& OldMaxStaminaBase) const;

	UFUNCTION()
	void OnRep_StaminaReBase(const FGameplayAttributeData& OldStaminaReBase) const;

	UFUNCTION()
	void OnRep_MaxFormBase(const FGameplayAttributeData& OldMaxFormBase) const;

	UFUNCTION()
	void OnRep_VitalityBase(const FGameplayAttributeData& OldVitalityBase) const;

	UFUNCTION()
	void OnRep_PrimalForceBase(const FGameplayAttributeData& OldPrimalForceBase) const;

	UFUNCTION()
	void OnRep_InsightBase(const FGameplayAttributeData& OldInsightBase) const;

	/**
	* 附加属性值
	*/
	UFUNCTION()
	void OnRep_MaxStaminaTemp(const FGameplayAttributeData& OldMaxStaminaTemp) const;

	UFUNCTION()
	void OnRep_StaminaReTemp(const FGameplayAttributeData& OldStaminaReTemp) const;

	UFUNCTION()
	void OnRep_MaxFormTemp(const FGameplayAttributeData& OldMaxFormTemp) const;

	UFUNCTION()
	void OnRep_VitalityTemp(const FGameplayAttributeData& OldVitalityTemp) const;

	UFUNCTION()
	void OnRep_PrimalForceTemp(const FGameplayAttributeData& OldPrimalForceTemp) const;

	UFUNCTION()
	void OnRep_InsightTemp(const FGameplayAttributeData& OldInsightTemp) const;

	/**
	* 最终属性值
	*/
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;

	UFUNCTION()
	void OnRep_StaminaRe(const FGameplayAttributeData& OldStaminaRe) const;
	
	UFUNCTION()
	void OnRep_Form(const FGameplayAttributeData& OldForm) const;

	UFUNCTION()
	void OnRep_MaxForm(const FGameplayAttributeData& OldMaxForm) const;

	UFUNCTION()
	void OnRep_Vitality(const FGameplayAttributeData& OldVitality) const;

	UFUNCTION()
	void OnRep_PrimalForce(const FGameplayAttributeData& OldPrimalForce) const;

	UFUNCTION()
	void OnRep_Insight(const FGameplayAttributeData& OldInsight) const;
};
