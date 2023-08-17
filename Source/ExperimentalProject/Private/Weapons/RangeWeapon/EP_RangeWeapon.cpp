#include "ExperimentalProject/Public/Weapons/RangeWeapon/EP_RangeWeapon.h"

#include "Components/EP_EquipmentComponent.h"
#include "Weapons/RangeWeapon/Projectiles/EP_BaseProjectile.h"


AEP_RangeWeapon::AEP_RangeWeapon()
{
	MagazineComponent = CreateDefaultSubobject<UEP_MagazineComponent>("MagazineComponent");
}


void AEP_RangeWeapon::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(WeaponInfo))
	{
		RangeWeaponInfo = Cast<UEP_RangeWeaponData>(WeaponInfo);
	}
}


void AEP_RangeWeapon::Shot()
{
	AEP_BaseProjectile* LBullet = GetWorld()->SpawnActorDeferred<AEP_BaseProjectile>(AmmoInChamber->ProjectileClass,
		Mesh->GetSocketTransform(RangeWeaponInfo->MuzzleSocketName));
	if (!IsValid(LBullet)) return;

	LBullet->InitializeProjectile();
	LBullet->FinishSpawning(Mesh->GetSocketTransform(RangeWeaponInfo->MuzzleSocketName));
	// Spawn particles
	// Spawn sound
	Super::Shot();
	AmmoInChamber = nullptr;

	FTimerHandle LTimerHandle;
	FTimerDelegate LTimerDelegate;

	LTimerDelegate.BindUObject(this, &AEP_RangeWeapon::PutCartridgeInChamber);
	GetWorldTimerManager().SetTimer(LTimerHandle, LTimerDelegate, WeaponInfo->TimeBetweenShots, false);
}


bool AEP_RangeWeapon::CanShoot()
{
	if (!Super::CanShoot() || !IsValid(AmmoInChamber)) return false;
	return true;
}


void AEP_RangeWeapon::Reload(float SkillFactor, float AdditionalReloadTime, AEP_BaseMagazine* NewAttachedMagazine)
{
	Super::Reload(SkillFactor, AdditionalReloadTime, NewAttachedMagazine);

	float reloadTime = RangeWeaponInfo->BaseReloadTime * SkillFactor *
		MagazineComponent->AttachedMagazine->MagazineInfo->ReloadCoefficient + AdditionalReloadTime;

	FTimerHandle LTimerHandle;
	FTimerDelegate LTimerDelegate;

	LTimerDelegate.BindUObject(this, &AEP_RangeWeapon::CheckAmmoInMagazine);
	GetWorldTimerManager().SetTimer(LTimerHandle, LTimerDelegate, MagazineComponent->AttachedMagazine->MagazineInfo->AmmoCheckTime, false);
	
	UE_LOG(LogTemp, Error, TEXT("Reload!"));
	PutCartridgeInChamber();
}


void AEP_RangeWeapon::DoCheckAmmo_Implementation(UEP_EquipmentComponent* EquipmentComponent)
{
	MagazineInfo.BindUObject(EquipmentComponent, &UEP_EquipmentComponent::OnAmmoChecked);
	if (IsValid(MagazineComponent->AttachedMagazine))
	{
		FTimerHandle LTimerHandle;
		FTimerDelegate LTimerDelegate;

		LTimerDelegate.BindUObject(this, &AEP_RangeWeapon::CheckAmmoInMagazine);
		GetWorldTimerManager().SetTimer(LTimerHandle, LTimerDelegate, MagazineComponent->AttachedMagazine->MagazineInfo->AmmoCheckTime, false);
		return;
	}

	FTimerHandle LTimerHandle;
	FTimerDelegate LTimerDelegate;

	LTimerDelegate.BindUObject(this, &AEP_RangeWeapon::CheckAmmoInChamber, false, -1);
	GetWorldTimerManager().SetTimer(LTimerHandle, LTimerDelegate, RangeWeaponInfo->ChamberCheckTime, false);
}


void AEP_RangeWeapon::CheckAmmoInMagazine()
{
	int32 LAmmoCount;
	MagazineComponent->CheckAmmoInMagazine(LAmmoCount);
	
	FTimerHandle LTimerHandle;
	FTimerDelegate LTimerDelegate;

	LTimerDelegate.BindUObject(this, &AEP_RangeWeapon::CheckAmmoInChamber, true, LAmmoCount);
	GetWorldTimerManager().SetTimer(LTimerHandle, LTimerDelegate, RangeWeaponInfo->ChamberCheckTime, false);
}


void AEP_RangeWeapon::CheckAmmoInChamber(bool InMagazineIsValid, int32 InAmmoInMagazine)
{
	MagazineInfo.Execute(InAmmoInMagazine, IsValid(AmmoInChamber), MagazineComponent->AttachedMagazine->GetTopBullet());
}


void AEP_RangeWeapon::PutCartridgeInChamber()
{
	int LAmmoCount; 
	if (!MagazineComponent->CheckAmmoInMagazine(LAmmoCount)) return;
	if (LAmmoCount == 0) return;
	
	AmmoInChamber = MagazineComponent->GetAndRemoveTopBullet();
	
	if (!IsValid(AmmoInChamber)) return;
	UE_LOG(LogTemp, Error, TEXT("Bullet in the chamber: %s"), *AmmoInChamber->BulletName.ToString()); // Debug
}

