// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XXGameEffectActor.generated.h"

class USkeletalMeshComponent;
class USphereComponent;

UCLASS()
class XX_API AXXGameEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AXXGameEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSwip,
		const FHitResult& SweepResult
	);

	UFUNCTION()
	virtual void OnSphereOverlapEnd(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
	);


private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* OverlapShpere;
};
