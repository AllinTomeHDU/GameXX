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
	void InitWidgetController();

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitWidgetControllerComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetWidgetControllerComplete();

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UObject* WidgetController;

	UPROPERTY(EditAnywhere, Category = "Widget Controller")
	TSubclassOf<UObject> WidgetControllerClass;

public:
	FORCEINLINE UObject* GetWidgetController() const { return WidgetController; }
};
