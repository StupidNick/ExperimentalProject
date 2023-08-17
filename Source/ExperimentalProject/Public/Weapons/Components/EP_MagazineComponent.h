#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapons/Magazines/EP_BaseMagazine.h"
#include "EP_MagazineComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERIMENTALPROJECT_API UEP_MagazineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UEP_MagazineComponent();

	UFUNCTION(BlueprintCallable, Category = "Magazine manipulation")
		bool AttachNewMagazine();

	UFUNCTION(BlueprintCallable, Category = "Magazine manipulation")
		bool DetachMagazine();

	UFUNCTION(BlueprintCallable, Category = "Magazine manipulation")
		bool CheckAmmoInMagazine(int& OutAmmoCount);

	UFUNCTION(BlueprintCallable, Category = "Magazine manipulation")
		UEP_AmmoInfo* GetAndRemoveTopBullet();

protected:
	
	virtual void BeginPlay() override;

public:

	UPROPERTY()
		AEP_BaseMagazine* AttachedMagazine;
};
