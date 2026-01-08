// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/Animation/MMAlsAnimInstanceBase.h"
#include "Proxy/XXNPCAnimInstanceProxy.h"
#include "XXNPCAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXNPCAnimInstance : public UMMAlsAnimInstanceBase
{
	GENERATED_BODY()
	
	friend struct FXXNPCAnimInstanceProxy;

	UPROPERTY(Transient)
	FXXNPCAnimInstanceProxy NPCProxy;

	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override { return &NPCProxy; }
	virtual void DestroyAnimInstanceProxy(FAnimInstanceProxy* InProxy) override {}
	
	
};
