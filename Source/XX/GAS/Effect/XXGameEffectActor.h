// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XXGameEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class XX_API AXXGameEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AXXGameEffectActor();

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> InEffectClass);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Applied Effects", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> InstanceGameplayEeffectClass;
};
