#include "ExperimentalProject/Public/Equipment/EP_BaseUnloadingVest.h"



AEP_BaseUnloadingVest::AEP_BaseUnloadingVest()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}


void AEP_BaseUnloadingVest::BeginPlay()
{
	Super::BeginPlay();

	for (auto info : UploadingVestInfo->Slots)
	{
		for (int i = 0; i < info.SlotCount; i++)
		{
			Slots.Add(FEP_UnloadingVestSlot(TArray<IEP_InventoryItemInteraction*>(), info.SlotVolume.IntPoint(), info.ReloadTimeCoefficient));
		}
	}
	for (auto slot : Slots)
	{
		UE_LOG(LogTemp, Error, TEXT("Slot volume after change: %f"), slot.SlotVolume.X);
	}
}