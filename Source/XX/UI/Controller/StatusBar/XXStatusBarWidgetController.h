// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "../XXWidgetControllerObject.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"
#include "XXStatusBarWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStaminaChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxStaminaChangedSignature, float, NewValue);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class XX_API UXXStatusBarWidgetController : public UXXWidgetControllerObject
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	
protected:
	virtual void BindCallbacksToDependencies() override;

	virtual void BroadcastCurrentValues() override;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChangedSignature OnMaxHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnManaChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnManaChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnStaminaChangedSignature OnStaminaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnStaminaChangedSignature OnMaxStaminaChanged;

private:
	void HealthChangedCallback(const FOnAttributeChangeData& Data) const;
	void MaxHealthChangedCallback(const FOnAttributeChangeData& Data) const;

	void ManaChangedCallback(const FOnAttributeChangeData& Data) const;
	void MaxManaChangedCallback(const FOnAttributeChangeData& Data) const;

	void StaminaChangedCallback(const FOnAttributeChangeData& Data) const;
	void MaxStaminaChangedCallback(const FOnAttributeChangeData& Data) const;
};
