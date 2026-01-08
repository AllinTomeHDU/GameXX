// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "XXUserWidgetBase.generated.h"

class UXXWidgetControllerObject;

/**
 * 
 */
UCLASS()
class XX_API UXXUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UXXWidgetControllerObject* InWidgetController);
	
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetWidgetControllerBP();

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UXXWidgetControllerObject* WidgetController;

public:
	FORCEINLINE UXXWidgetControllerObject* GetWidgetController() const { return WidgetController; }
};
