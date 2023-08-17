#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EP_UnloadingVestInfo.generated.h"



USTRUCT()
struct FUnloadingSlotInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (ClampMin = "1", Multiple = 1, Delta = 1))
		FVector2D SlotVolume;

	UPROPERTY(EditDefaultsOnly)
		float SlotCount = 1;

	UPROPERTY(EditDefaultsOnly)
		float ReloadTimeCoefficient = 1;
};



UCLASS()
class EXPERIMENTALPROJECT_API UEP_UnloadingVestInfo : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		FText Name;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		TArray<FUnloadingSlotInfo> Slots;
};