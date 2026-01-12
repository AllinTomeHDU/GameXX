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
	* 最终属性值
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "TotalAttributes|Status")
	FGameplayAttributeData Stamina;	// 体力值
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "TotalAttributes|Status")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, MaxStamina);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	
	
};
