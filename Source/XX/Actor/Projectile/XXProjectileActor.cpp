// Copyright: Jichao Luo


#include "XXProjectileActor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


AXXProjectileActor::AXXProjectileActor()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	SetRootComponent(OverlapSphere);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
}

void AXXProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	
	OverlapSphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);

}

void AXXProjectileActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

