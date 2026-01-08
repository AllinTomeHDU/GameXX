// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "XXGameHUD.generated.h"

class AXXHeroPlayerController;
class AXXHeroPlayerState;
class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;

class UXXUserWidgetBase;
class UXXWidgetControllerObject;


/**
 * 
 */
UCLASS()
class XX_API AXXGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	void InitOverlay(
		AXXHeroPlayerController* PC,
		AXXHeroPlayerState* PS,
		UXXBaseAbilitySystemComponent* ASC,
		UXXBaseAttributeSet* AS
	);
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Overlay", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UXXUserWidgetBase> OverlayWidgetClass;

	UPROPERTY()
	UXXUserWidgetBase* OverlayWidget;

	UPROPERTY()
	UXXWidgetControllerObject* OverlayWidgetController;

public:
	FORCEINLINE UXXWidgetControllerObject* GetOverlayWidgetController() const { return OverlayWidgetController; }

};
