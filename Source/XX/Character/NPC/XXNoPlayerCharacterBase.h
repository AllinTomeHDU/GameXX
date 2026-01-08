// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "../XXCharacterBase.h"
#include "XXNoPlayerCharacterBase.generated.h"

/**
 *
 */
UCLASS(Abstract)
class XX_API AXXNoPlayerCharacterBase : public AXXCharacterBase
{
	GENERATED_BODY()

public:
	AXXNoPlayerCharacterBase(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

protected:

	
};
