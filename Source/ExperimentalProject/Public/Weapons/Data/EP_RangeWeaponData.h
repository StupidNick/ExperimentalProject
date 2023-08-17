#pragma once

#include "CoreMinimal.h"
#include "EP_WeaponData.h"
#include "EP_RangeWeaponData.generated.h"



UCLASS()
class EXPERIMENTALPROJECT_API UEP_RangeWeaponData : public UEP_WeaponData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, Category = "Info")
		FName MuzzleSocketName;

	UPROPERTY(EditDefaultsOnly, Category = "Ammo check")
		float ChamberCheckTime;

	UPROPERTY(EditDefaultsOnly, Category = "Reload")
		float BaseReloadTime;
};
