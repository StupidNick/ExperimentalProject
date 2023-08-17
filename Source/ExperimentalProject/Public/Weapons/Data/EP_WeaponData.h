#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EP_WeaponData.generated.h"



UCLASS()
class EXPERIMENTALPROJECT_API UEP_WeaponData : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, Category = "Shooting")
	float TimeBetweenShots;
};
