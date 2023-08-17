#include "ExperimentalProject/Public/Components/EP_EquipmentComponent.h"

#include "Characters/EP_BaseCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Weapons/RangeWeapon/EP_RangeWeapon.h"


UEP_EquipmentComponent::UEP_EquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UEP_EquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<AEP_BaseCharacter>(GetOwner());
	check(Character);

	AddWeapon(GetWorld()->SpawnActor<AEP_BaseWeapon>(StartWeapon,
		Character->GetMesh1P()->GetSocketTransform(Character->WeaponSocketName)));

	UnloadingVest = GetWorld()->SpawnActor<AEP_BaseUnloadingVest>(StartUnloadingVest,
		Character->GetMesh1P()->GetComponentTransform());
	for (int i = 0; i < StartMagazineCount; i++)
	{
		// UnloadingVest->Slots[i].AddItemToSlot(GetWorld()->SpawnActor<AEP_BaseMagazine>(StartMagazine, UnloadingVest));
	}

	auto weapon = Cast<AEP_RangeWeapon>(FirstWeaponSlot);
	weapon->MagazineComponent->AttachedMagazine = GetWorld()->SpawnActor<AEP_BaseMagazine>(StartMagazine,
		weapon->Mesh->GetSocketTransform("Magazine"));
	weapon->MagazineComponent->AttachedMagazine->AttachToComponent(weapon->Mesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false), "Magazine");
	weapon->MagazineComponent->AttachedMagazine->Mesh->SetCollisionProfileName("AttachedWeapon");

	for (int i = 0; i < 5; i++)
	{
		weapon->MagazineComponent->AttachedMagazine->AddBulletToMagazine(StartAmmo);
	}
	// weapon->DoReload_Implementation();
}


AActor* UEP_EquipmentComponent::GetItemInHand() const
{
	return HandSlot;
}


void UEP_EquipmentComponent::StartFire()
{
	if (!UKismetSystemLibrary::DoesImplementInterface(HandSlot, UEP_InteractionWithWeapon::StaticClass())) return;

	IEP_InteractionWithWeapon::Execute_DoShot(HandSlot);
}


void UEP_EquipmentComponent::SlowReloadWeapon()
{
	if (!UKismetSystemLibrary::DoesImplementInterface(HandSlot, UEP_InteractionWithWeapon::StaticClass())) return;

	// IEP_InteractionWithWeapon::Execute_DoReload(HandSlot, 1, 2, NewAttachedMagazine);
}


void UEP_EquipmentComponent::QuickReloadWeapon()
{
	if (!UKismetSystemLibrary::DoesImplementInterface(HandSlot, UEP_InteractionWithWeapon::StaticClass())) return;

	// IEP_InteractionWithWeapon::Execute_DoReload(HandSlot, 1, 0, NewAttachedMagazine);
}


void UEP_EquipmentComponent::CheckAmmoInWeapon()
{
	if (!UKismetSystemLibrary::DoesImplementInterface(HandSlot, UEP_InteractionWithWeapon::StaticClass())) return;

	IEP_InteractionWithWeapon::Execute_DoCheckAmmo(HandSlot, this);
}


void UEP_EquipmentComponent::OnAmmoChecked(int32 InAmmoInMagazineCount, bool InAmmoInChamber, UEP_AmmoInfo* InTopBulletInfo)
{
	UE_LOG(LogTemp, Error, TEXT("Ammo in magazine: %i"), InAmmoInMagazineCount);
	if (InAmmoInChamber)
	{
		UE_LOG(LogTemp, Error, TEXT("One in chamber"));
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("Empty chamber"));
}


void UEP_EquipmentComponent::AddWeapon(AEP_BaseWeapon* InNewWeapon)
{
	FirstWeaponSlot = InNewWeapon;
	HandSlot = InNewWeapon;
	HandSlot->AttachToComponent(Character->GetMesh1P(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false), Character->WeaponSocketName);
	InNewWeapon->Mesh->SetCollisionProfileName("AttachedWeapon");
}
