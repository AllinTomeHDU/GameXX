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
 * 
 */
UCLASS()
class XX_API UXXBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UXXBaseAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

public:
	/**
	* 基本属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData HealthBase;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, HealthBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealthBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData MaxHealthBase;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxHealthBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData ManaBase;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, ManaBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxManaBase, Category = "BaseAttributes|Status")
	FGameplayAttributeData MaxManaBase;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxManaBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackBase, Category = "BaseAttributes|Combat")
	FGameplayAttributeData AttackBase;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, AttackBase);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DefenseBase, Category = "BaseAttributes|Combat")
	FGameplayAttributeData DefenseBase;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, DefenseBase);

	/**
	* 附加属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData HealthTemp;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, HealthTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealthTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData MaxHealthTemp;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxHealthTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData ManaTemp;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, ManaTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxManaTemp, Category = "TempAttributes|Status")
	FGameplayAttributeData MaxManaTemp;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxManaTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackTemp, Category = "TempAttributes|Combat")
	FGameplayAttributeData AttackTemp;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, AttackTemp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DefenseTemp, Category = "TempAttributes|Combat")
	FGameplayAttributeData DefenseTemp;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, DefenseTemp);


	/**
	* 最终属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "TotalAttributes|Status")
	FGameplayAttributeData Health;  // 生命值
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "TotalAttributes|Status")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "TotalAttributes|Status")
	FGameplayAttributeData Mana;  // 法力值
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "TotalAttributes|Status")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attack, Category = "TotalAttributes|Combat")
	FGameplayAttributeData Attack;  // 攻击力
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Attack);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Defense, Category = "TotalAttributes|Combat")
	FGameplayAttributeData Defense;  // 防御力
	ATTRIBUTE_ACCESSORS(UXXBaseAttributeSet, Defense);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	/**
	* Base
	*/
	UFUNCTION()
	void OnRep_HealthBase(const FGameplayAttributeData& OldHealthBase) const;

	UFUNCTION()
	void OnRep_MaxHealthBase(const FGameplayAttributeData& OldMaxHealthBase) const;

	UFUNCTION()
	void OnRep_ManaBase(const FGameplayAttributeData& OldManaBase) const;

	UFUNCTION()
	void OnRep_MaxManaBase(const FGameplayAttributeData& OldMaxManaBase) const;

	UFUNCTION()
	void OnRep_AttackBase(const FGameplayAttributeData& OldAttackBase) const;

	UFUNCTION()
	void OnRep_DefenseBase(const FGameplayAttributeData& OldDefenseBase) const;

	/**
	* Temp
	*/
	UFUNCTION()
	void OnRep_HealthTemp(const FGameplayAttributeData& OldHealthTemp) const;

	UFUNCTION()
	void OnRep_MaxHealthTemp(const FGameplayAttributeData& OldMaxHealthTemp) const;

	UFUNCTION()
	void OnRep_ManaTemp(const FGameplayAttributeData& OldManaTemp) const;

	UFUNCTION()
	void OnRep_MaxManaTemp(const FGameplayAttributeData& OldMaxManaTemp) const;

	UFUNCTION()
	void OnRep_AttackTemp(const FGameplayAttributeData& OldAttackTemp) const;

	UFUNCTION()
	void OnRep_DefenseTemp(const FGameplayAttributeData& OldDefenseTemp) const;

	/**
	* Total
	*/
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_Attack(const FGameplayAttributeData& OldAttack) const;

	UFUNCTION()
	void OnRep_Defense(const FGameplayAttributeData& OldDefense) const;
	
};
