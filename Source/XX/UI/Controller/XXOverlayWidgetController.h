// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "XXWidgetControllerObject.h"
#include "XXOverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewValue);

/**
 * 
 */
UCLASS()
class XX_API UXXOverlayWidgetController : public UXXWidgetControllerObject
{
	GENERATED_BODY()
	
protected:

	virtual void BroadcastInitialValues();

	UPROPERTY(BlueprintAssignable)
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChangedSignature OnMaxHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnManaChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnManaChangedSignature OnMaxManaChanged;
};
