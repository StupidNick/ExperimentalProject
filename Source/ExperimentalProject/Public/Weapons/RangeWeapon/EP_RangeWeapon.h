#pragma once

#include "CoreMinimal.h"
#include "ExperimentalProject/Public/Weapons/EP_BaseWeapon.h"
#include "Weapons/Components/EP_MagazineComponent.h"
#include "Weapons/Data/EP_RangeWeaponData.h"
#include "Weapons/Magazines/Data/EP_AmmoInfo.h"
#include "EP_RangeWeapon.generated.h"



DECLARE_DELEGATE_ThreeParams(FMagazineInfo, int32, bool, UEP_AmmoInfo*);
UCLASS()
class EXPERIMENTALPROJECT_API AEP_RangeWeapon : public AEP_BaseWeapon
{
	GENERATED_BODY()

public:

	AEP_RangeWeapon();

	virtual void DoCheckAmmo_Implementation(UEP_EquipmentComponent* EquipmentComponent) override;

protected:

	virtual void BeginPlay() override;

	virtual void Shot() override;
	virtual bool CanShoot() override;
	virtual void Reload(float SkillFactor, float AdditionalReloadTime, AEP_BaseMagazine* NewAttachedMagazine) override;

	void CheckAmmoInMagazine();
	
	void CheckAmmoInChamber(bool InMagazineIsValid, int32 InAmmoInMagazine);

	UFUNCTION()
		void PutCartridgeInChamber();

	UPROPERTY()
		UEP_RangeWeaponData* RangeWeaponInfo;

public:
	
	UPROPERTY()
		UEP_AmmoInfo* AmmoInChamber = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UEP_MagazineComponent* MagazineComponent = nullptr;

	FMagazineInfo MagazineInfo;
};


