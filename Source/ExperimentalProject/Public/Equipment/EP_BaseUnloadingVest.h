#pragma once

#include "CoreMinimal.h"
#include "Data/EP_UnloadingVestInfo.h"
#include "Data/EP_UnloadingVestSlot.h"
#include "GameFramework/Actor.h"
#include "EP_BaseUnloadingVest.generated.h"



UCLASS()
class EXPERIMENTALPROJECT_API AEP_BaseUnloadingVest : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AEP_BaseUnloadingVest();

	// bool EquipItem(UEP_InventoryItemInteraction);

protected:
	
	virtual void BeginPlay() override;

public:

	TArray<FEP_UnloadingVestSlot> Slots;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		UEP_UnloadingVestInfo* UploadingVestInfo;
};
