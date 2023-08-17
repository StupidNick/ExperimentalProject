#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Weapons/RangeWeapon/Projectiles/Data/EP_WeaponCalibers.h"
#include "EP_AmmoInfo.generated.h"



class AEP_BaseProjectile;



UCLASS()
class EXPERIMENTALPROJECT_API UEP_AmmoInfo : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		TSubclassOf<AEP_BaseProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		FText BulletName;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		TEnumAsByte<EEP_WeaponCalibers> BulletCaliber;
};
