#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Weapons/RangeWeapon/Projectiles/Data/EP_WeaponCalibers.h"
#include "EP_MagazineData.generated.h"



UCLASS()
class EXPERIMENTALPROJECT_API UEP_MagazineData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Magazine info")
		int32 MaxNumOfAmmo;
	
	UPROPERTY(EditDefaultsOnly, Category = "Magazine info")
		float AmmoCheckTime;

	UPROPERTY(EditDefaultsOnly, Category = "Magazine info")
		float ReloadCoefficient;

	UPROPERTY(EditDefaultsOnly, Category = "Magazine info")
		TEnumAsByte<EEP_WeaponCalibers> AmmoCaliber;
};
