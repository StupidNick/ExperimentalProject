#pragma once

#include "Interfaces/EP_InventoryItemInteraction.h"
#include "EP_UnloadingVestSlot.generated.h"



USTRUCT()
struct FEP_UnloadingVestSlot
{
	GENERATED_BODY()

	FEP_UnloadingVestSlot(){}

	FEP_UnloadingVestSlot(TArray<IEP_InventoryItemInteraction*> InItem, FIntPoint InSlotVolume, float InTakeTimeCoefficient)
	{
		Item = InItem;
		SlotVolume.X = InSlotVolume.X;
		SlotVolume.Y = InSlotVolume.Y;
		TakeTimeCoefficient = InTakeTimeCoefficient;
	}

	bool AddItemToSlot(IEP_InventoryItemInteraction* InItem, int NumberOfSlot)
	{
		if (NumberOfSlot) // TODO check is valid place in slot
		{
			
		}
		Item.Add(InItem);
	}

	TArray<IEP_InventoryItemInteraction*> Item;

	UPROPERTY()
		FVector2D SlotVolume;

	UPROPERTY()
		float TakeTimeCoefficient;
};