#include "ExperimentalProject/Public/Weapons/Magazines/EP_BaseMagazine.h"



AEP_BaseMagazine::AEP_BaseMagazine()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}


void AEP_BaseMagazine::BeginPlay()
{
	Super::BeginPlay();
}


bool AEP_BaseMagazine::AddBulletToMagazine(UEP_AmmoInfo* inBulletInfo)
{
	if (!IsValid(inBulletInfo) || MagazineInfo->MaxNumOfAmmo <= BulletStack.Num()) return false;
	if (inBulletInfo->BulletCaliber != MagazineInfo->AmmoCaliber) return false;

	UE_LOG(LogTemp, Error, TEXT("Add ammo %s to magazine"), *inBulletInfo->BulletName.ToString());
	return BulletStack.AddHead(inBulletInfo);
}


UEP_AmmoInfo* AEP_BaseMagazine::GetTopBullet() const
{
	return BulletStack.GetHead()->GetValue();
}


void AEP_BaseMagazine::RemoveTopBullet()
{
	if (BulletStack.GetHead() == nullptr) return;

	BulletStack.RemoveNode(BulletStack.GetHead());
}


int AEP_BaseMagazine::GetBulletCount() const
{
	return BulletStack.Num();
}

float AEP_BaseMagazine::GetSlotVolume_Implementation()
{
	return 0;
}
