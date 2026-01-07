// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "XXNoPlayerCharacterBase.generated.h"

UCLASS(Abstract)
class XX_API AXXNoPlayerCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AXXNoPlayerCharacterBase();

protected:
	virtual void BeginPlay() override;

private:

	
	
};
