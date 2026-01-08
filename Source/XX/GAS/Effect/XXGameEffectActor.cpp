// Copyright: Jichao Luo


#include "XXGameEffectActor.h"
#include "XX/GAS/Interface/XXGASInterface.h"
#include "XX/GAS/AbilitySystem/XXBaseAbilitySystemComponent.h"
#include "XX/GAS/AttributeSet/XXBaseAttributeSet.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"


AXXGameEffectActor::AXXGameEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EffectActorMesh"));
	SetRootComponent(Mesh);

	OverlapShpere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	OverlapShpere->SetupAttachment(Mesh);
}

void AXXGameEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	OverlapShpere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnSphereOverlap);
	OverlapShpere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnSphereOverlapEnd);
}

void AXXGameEffectActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSwip, const FHitResult& SweepResult)
{
	if (auto GASInterface = Cast<IXXGASInterface>(OtherActor))
	{
		if (auto AS = GASInterface->GetBaseAttributeSet())
		{
			AS->SetHealth(AS->GetHealth() + 20.f);
			Destroy();
		}

		//UXXBaseAbilitySystemComponent* ASC = GASInterface->GetAbilitySystemComponent();
		//if (!IsValid(ASC)) return;

		//if (const UXXBaseAttributeSet* AS = Cast<UXXBaseAttributeSet>(ASC->GetAttributeSet(UXXBaseAttributeSet::StaticClass())))
		//{
		//	AS;
		//}
	}
}

void AXXGameEffectActor::OnSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
