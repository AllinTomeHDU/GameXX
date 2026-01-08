// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "XXNoPlayerCharacterBase.h"
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
};
