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

	virtual void InitAttributes(const TArray<TSubclassOf<UGameplayEffect>>& EffectClassArr, float Level) override;

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

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void OnMaxStaminaChanged(const FOnAttributeChangeData& Data);

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

	/**
	* 附加属性值
	*/
	UFUNCTION()
	void OnRep_MaxStaminaTemp(const FGameplayAttributeData& OldMaxStaminaTemp) const;

	UFUNCTION()
	void OnRep_StaminaReTemp(const FGameplayAttributeData& OldStaminaReTemp) const;

	UFUNCTION()
	void OnRep_MaxFormTemp(const FGameplayAttributeData& OldMaxFormTemp) const;

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
};
