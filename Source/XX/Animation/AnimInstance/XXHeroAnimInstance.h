// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/Animation/MMAlsAnimInstance.h"
#include "Proxy/XXHeroAnimInstanceProxy.h"
#include "XXHeroAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXHeroAnimInstance : public UMMAlsAnimInstance
{
	GENERATED_BODY()
	
	friend struct FXXHeroAnimInstanceProxy;

	UPROPERTY(Transient)
	FXXHeroAnimInstanceProxy HeroProxy;

	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override { return &HeroProxy; }
	virtual void DestroyAnimInstanceProxy(FAnimInstanceProxy* InProxy) override {}

protected:
	
	
};
