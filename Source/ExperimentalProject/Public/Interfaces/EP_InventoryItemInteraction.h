#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EP_InventoryItemInteraction.generated.h"



class EUnloadingVestSlotType;


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEP_InventoryItemInteraction : public UInterface
{
	GENERATED_BODY()
};


class EXPERIMENTALPROJECT_API IEP_InventoryItemInteraction
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Getters")
		float GetSlotVolume();

	// UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Equip")
	// 	void Equip();
};