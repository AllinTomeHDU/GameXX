// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "XXWidgetControllerObject.generated.h"

class AXXHeroPlayerController;
class AXXHeroPlayerState;
class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;

USTRUCT()
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() {}
	FWidgetControllerParams(
		AXXHeroPlayerController* PC,
		AXXHeroPlayerState* PS,
		UXXBaseAbilitySystemComponent* ASC,
		UXXBaseAttributeSet* AS
	) : PlayerController(PC), PlayerState(PS), AbilitySystem(ASC), AttributeSet(AS) {}

	AXXHeroPlayerController* PlayerController;

	AXXHeroPlayerState* PlayerState;

	UXXBaseAbilitySystemComponent* AbilitySystem;

	UXXBaseAttributeSet* AttributeSet;
};


/**
 * 
 */
UCLASS()
class XX_API UXXWidgetControllerObject : public UObject
{
	GENERATED_BODY()

public:
	void SetWidgetControllerParams(const FWidgetControllerParams& Params);
	
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
