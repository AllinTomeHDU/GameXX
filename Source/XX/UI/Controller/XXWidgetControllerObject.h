// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "XXWidgetControllerObject.generated.h"

class AXXHeroPlayerController;
class AXXHeroPlayerState;
class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;

/**
 * 
 */
UCLASS()
class XX_API UXXWidgetControllerObject : public UObject
{
	GENERATED_BODY()

public:
	virtual void Init();

	virtual void BindCallbacksToDependencies() {};

	UFUNCTION(BlueprintCallable)
	virtual void BroadcastCurrentValues() {};

protected:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AXXHeroPlayerController* PlayerController;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AXXHeroPlayerState* PlayerState;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UXXBaseAbilitySystemComponent* AbilitySystem;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UXXBaseAttributeSet* AttributeSet;

};
