// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "XXNoPlayerCharacterBase.h"
#include "XX/UI/Controller/StatusBar/XXStatusBarWidgetController.h"
#include "XXEnemyCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class XX_API AXXEnemyCharacterBase : public AXXNoPlayerCharacterBase
{
	GENERATED_BODY()
	
public:
	AXXEnemyCharacterBase(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual void BeginPlay() override;

	void InitHeadTopWidget();

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;
};
