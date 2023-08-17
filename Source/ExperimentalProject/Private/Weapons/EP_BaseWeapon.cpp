#include "ExperimentalProject/Public/Weapons/EP_BaseWeapon.h"

#include "Kismet/GameplayStatics.h"


AEP_BaseWeapon::AEP_BaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}


void AEP_BaseWeapon::BeginPlay()
{
	Super::BeginPlay();
}


bool AEP_BaseWeapon::CanShoot()
{
	if (NextShootTime > UGameplayStatics::GetTimeSeconds(GetWorld())) return false;
	return true;
}


bool AEP_BaseWeapon::DoReload_Implementation(float SkillFactor, float AdditionalReloadTime, AEP_BaseMagazine* NewAttachedMagazine)
{
	Reload(SkillFactor, AdditionalReloadTime, NewAttachedMagazine);
	return true;
}


bool AEP_BaseWeapon::DoShot_Implementation()
{
	if (!CanShoot()) return false;

	Shot();
	return true;
}


void AEP_BaseWeapon::Shot()
{
	NextShootTime = UGameplayStatics::GetTimeSeconds(GetWorld()) + WeaponInfo->TimeBetweenShots;
}


void AEP_BaseWeapon::Reload(float SkillFactor, float AdditionalReloadTime, AEP_BaseMagazine* NewAttachedMagazine){}
