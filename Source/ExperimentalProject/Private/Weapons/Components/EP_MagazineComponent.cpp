#include "ExperimentalProject/Public/Weapons/Components/EP_MagazineComponent.h"



UEP_MagazineComponent::UEP_MagazineComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UEP_MagazineComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


bool UEP_MagazineComponent::AttachNewMagazine()
{
	return false;
}


bool UEP_MagazineComponent::DetachMagazine()
{
	return false;
}


bool UEP_MagazineComponent::CheckAmmoInMagazine(int& OutAmmoCount)
{
	OutAmmoCount = -1;
	if (!IsValid(AttachedMagazine)) return false;
	
	OutAmmoCount = AttachedMagazine->GetBulletCount();
	UE_LOG(LogTemp, Error, TEXT("%s, Ammo: %i"), *AttachedMagazine->GetName(), OutAmmoCount);
	return true;
}


UEP_AmmoInfo* UEP_MagazineComponent::GetAndRemoveTopBullet()
{
	UEP_AmmoInfo* LBulletInfo = AttachedMagazine->GetTopBullet();
	AttachedMagazine->RemoveTopBullet();
	return LBulletInfo;
}