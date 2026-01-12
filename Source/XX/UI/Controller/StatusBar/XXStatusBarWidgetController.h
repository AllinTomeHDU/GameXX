// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "../XXWidgetControllerObject.h"
#include "XX/GAS/AttributeSet/XXHeroAttributeSet.h"
#include "XXStatusBarWidgetController.generated.h"


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class XX_API UXXStatusBarWidgetController : public UXXWidgetControllerObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void BroadcastCurrentValues();
	
protected:
	virtual void BindCallbacksToDependencies() override;

protected:
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnStaminaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxStaminaChanged;

private:
	void HealthChangedCallback(const FOnAttributeChangeData& Data) const;
	void MaxHealthChangedCallback(const FOnAttributeChangeData& Data) const;

	void ManaChangedCallback(const FOnAttributeChangeData& Data) const;
	void MaxManaChangedCallback(const FOnAttributeChangeData& Data) const;

	void StaminaChangedCallback(const FOnAttributeChangeData& Data) const;
	void MaxStaminaChangedCallback(const FOnAttributeChangeData& Data) const;
};
