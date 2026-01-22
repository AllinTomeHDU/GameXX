// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "XXBaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 关于各项属性值之间的关系，Primary是主要属性，不依赖与其他属性
 * Base属性在角色构造时初始化Instance，每个角色都有自己对应的GE_Base
 * Add为受Primary影响而附加的属性，由Primary的Total计算得出，Infinite
 * Temp是临时属性，由装备、道具临时添加
 * 次要属性的Total=Base+Add+Temp，主要属性的Total=Base+Temp
 */
UCLASS()
class XX_API UXXBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UXXBaseAttributeSet();

	virtual void InitAttributes(const TArray<TSubclassOf<UGameplayEffect>>& EffectClassArr, float Level = 1.f);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

public:
	/**
	* 基本属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealthBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData MaxHealthBase;  // 最大生命值
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxHealthBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthReBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData HealthReBase;  // 生命回复
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, HealthReBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxManaBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData MaxManaBase;  // 最大灵力值
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxManaBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaReBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData ManaReBase;  // 灵力回复
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, ManaReBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackBase, Category = "BaseAttributes|Combat")
	FGameplayAttributeData AttackBase;  // 攻击力
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, AttackBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DefenseBase, Category = "BaseAttributes|Combat")
	FGameplayAttributeData DefenseBase;  // 防御力
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, DefenseBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VitalityBase, Category = "BaseAttributes|Primary")
	FGameplayAttributeData VitalityBase;	// 体魄
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, VitalityBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PrimalForceBase, Category = "BaseAttributes|Primary")
	FGameplayAttributeData PrimalForceBase;	// 本源
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, PrimalForceBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_InsightBase, Category = "BaseAttributes|Primary")
	FGameplayAttributeData InsightBase;	// 悟性
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, InsightBase);

	/**
	* 附加属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealthTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData MaxHealthTemp;  // 最大生命值
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxHealthTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthReTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData HealthReTemp;  // 生命回复
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, HealthReTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxManaTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData MaxManaTemp;  // 最大灵力值
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxManaTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaReTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData ManaReTemp;  // 灵力回复
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, ManaReTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackTemp, Category = "TempAttributes|Combat")
	FGameplayAttributeData AttackTemp;  // 攻击力
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, AttackTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DefenseTemp, Category = "TempAttributes|Combat")
	FGameplayAttributeData DefenseTemp;  // 防御力
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, DefenseTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VitalityTemp, Category = "TempAttributes|Primary")
	FGameplayAttributeData VitalityTemp;	// 体魄
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, VitalityTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PrimalForceTemp, Category = "TempAttributes|Primary")
	FGameplayAttributeData PrimalForceTemp;	// 本源
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, PrimalForceTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_InsightTemp, Category = "TempAttributes|Primary")
	FGameplayAttributeData InsightTemp;	// 悟性
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, InsightTemp);


	/**
	* 最终属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "TotalAttributes|Status")
	FGameplayAttributeData Health;  // 生命值：直接进行加减计算的当前值
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "TotalAttributes|Status")
	FGameplayAttributeData MaxHealth;  // 最大生命值 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRe, Category = "TotalAttributes|Status")
	FGameplayAttributeData HealthRe;  // 生命回复 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, HealthRe);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "TotalAttributes|Status")
	FGameplayAttributeData Mana;  // 灵力值：直接进行加减计算的当前值
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "TotalAttributes|Status")
	FGameplayAttributeData MaxMana;  // 最大灵力值 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRe, Category = "TotalAttributes|Status")
	FGameplayAttributeData ManaRe;  // 灵力回复 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, ManaRe);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attack, Category = "TotalAttributes|Combat")
	FGameplayAttributeData Attack;  // 攻击力 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Attack);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Defense, Category = "TotalAttributes|Combat")
	FGameplayAttributeData Defense;  // 防御力 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Defense);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vitality, Category = "TotalAttributes|Primary")
	FGameplayAttributeData Vitality;	// 体魄 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Vitality);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PrimalForce, Category = "TotalAttributes|Primary")
	FGameplayAttributeData PrimalForce;	// 本源 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, PrimalForce);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Insight, Category = "TotalAttributes|Primary")
	FGameplayAttributeData Insight;	// 悟性 = Base + Temp
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Insight);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void OnMaxHealthChanged(const FOnAttributeChangeData& Data);
	virtual void OnMaxManaChanged(const FOnAttributeChangeData& Data);

private:
	/**
	* Base
	*/
	UFUNCTION()
	void OnRep_MaxHealthBase(const FGameplayAttributeData& OldMaxHealthBase) const;

	UFUNCTION()
	void OnRep_HealthReBase(const FGameplayAttributeData& OldHealthReBase) const;

	UFUNCTION()
	void OnRep_MaxManaBase(const FGameplayAttributeData& OldMaxManaBase) const;

	UFUNCTION()
	void OnRep_ManaReBase(const FGameplayAttributeData& OldManaBase) const;

	UFUNCTION()
	void OnRep_AttackBase(const FGameplayAttributeData& OldAttackBase) const;

	UFUNCTION()
	void OnRep_DefenseBase(const FGameplayAttributeData& OldDefenseBase) const;

	UFUNCTION()
	void OnRep_VitalityBase(const FGameplayAttributeData& OldVitalityBase) const;

	UFUNCTION()
	void OnRep_PrimalForceBase(const FGameplayAttributeData& OldPrimalForceBase) const;

	UFUNCTION()
	void OnRep_InsightBase(const FGameplayAttributeData& OldInsightBase) const;

	/**
	* Temp
	*/
	UFUNCTION()
	void OnRep_MaxHealthTemp(const FGameplayAttributeData& OldMaxHealthTemp) const;

	UFUNCTION()
	void OnRep_HealthReTemp(const FGameplayAttributeData& OldHealthReTemp) const;

	UFUNCTION()
	void OnRep_MaxManaTemp(const FGameplayAttributeData& OldMaxManaTemp) const;

	UFUNCTION()
	void OnRep_ManaReTemp(const FGameplayAttributeData& OldManaReTemp) const;

	UFUNCTION()
	void OnRep_AttackTemp(const FGameplayAttributeData& OldAttackTemp) const;

	UFUNCTION()
	void OnRep_DefenseTemp(const FGameplayAttributeData& OldDefenseTemp) const;

	UFUNCTION()
	void OnRep_VitalityTemp(const FGameplayAttributeData& OldVitalityTemp) const;

	UFUNCTION()
	void OnRep_PrimalForceTemp(const FGameplayAttributeData& OldPrimalForceTemp) const;

	UFUNCTION()
	void OnRep_InsightTemp(const FGameplayAttributeData& OldInsightTemp) const;

	/**
	* Total
	*/
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	void OnRep_HealthRe(const FGameplayAttributeData& OldHealthRe) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_ManaRe(const FGameplayAttributeData& OldManaRe) const;

	UFUNCTION()
	void OnRep_Attack(const FGameplayAttributeData& OldAttack) const;

	UFUNCTION()
	void OnRep_Defense(const FGameplayAttributeData& OldDefense) const;

	UFUNCTION()
	void OnRep_Vitality(const FGameplayAttributeData& OldVitality) const;

	UFUNCTION()
	void OnRep_PrimalForce(const FGameplayAttributeData& OldPrimalForce) const;

	UFUNCTION()
	void OnRep_Insight(const FGameplayAttributeData& OldInsight) const;
};
