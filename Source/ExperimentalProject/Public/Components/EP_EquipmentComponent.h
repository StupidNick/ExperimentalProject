#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Equipment/EP_BaseUnloadingVest.h"
#include "ExperimentalProject/Public/Weapons/EP_BaseWeapon.h"
#include "Weapons/Magazines/EP_BaseMagazine.h"
#include "EP_EquipmentComponent.generated.h"



class UEP_AmmoInfo;
class AEP_BaseCharacter;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERIMENTALPROJECT_API UEP_EquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UEP_EquipmentComponent();

	UFUNCTION()
		AActor* GetItemInHand() const;

	UFUNCTION()
		void StartFire();

	UFUNCTION()
		void SlowReloadWeapon();

	UFUNCTION()
		void QuickReloadWeapon();

	UFUNCTION()
		void CheckAmmoInWeapon();

	UFUNCTION()
		void OnAmmoChecked(int32 InAmmoInMagazineCount, bool InAmmoInChamber, UEP_AmmoInfo* InTopBulletInfo);

	UFUNCTION()
		void AddWeapon(AEP_BaseWeapon* InNewWeapon);

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Test")
		TSubclassOf<AEP_BaseWeapon> StartWeapon;
	UPROPERTY(EditDefaultsOnly, Category = "Test")
		TSubclassOf<AEP_BaseMagazine> StartMagazine;
	UPROPERTY(EditDefaultsOnly, Category = "Test")
		float StartMagazineCount;
	UPROPERTY(EditDefaultsOnly, Category = "Test")
		UEP_AmmoInfo* StartAmmo;
	UPROPERTY(EditDefaultsOnly, Category = "Test")
		TSubclassOf<AEP_BaseUnloadingVest> StartUnloadingVest;

private:

	UPROPERTY()
		AActor* HandSlot = nullptr;

	UPROPERTY()
		AEP_BaseWeapon* FirstWeaponSlot = nullptr;
	UPROPERTY()
		AEP_BaseWeapon* SecondWeaponSlot = nullptr;
	// UPROPERTY(EditDefaultsOnly, Category = "Weapon slots")
	// 	AEP_BaseWeapon* PistolSlot = nullptr;
	// UPROPERTY(EditDefaultsOnly, Category = "Weapon slots")
	// 	AEP_BaseWeapon* KnifeSlot = nullptr;

	UPROPERTY()
		AEP_BaseUnloadingVest* UnloadingVest = nullptr;

	UPROPERTY()
		AEP_BaseCharacter* Character;
};
