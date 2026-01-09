// Copyright: Jichao Luo

#pragma once

#include "XXBaseAttributeSet.h"
#include "XXHeroAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXHeroAttributeSet : public UXXBaseAttributeSet
{
	GENERATED_BODY()

public:
	UXXHeroAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Base Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Base Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UXXHeroAttributeSet, MaxStamina);

private:
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	
	
};
