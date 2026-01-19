// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XXProjectileActor.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class XX_API AXXProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AXXProjectileActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* OverlapSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
};
