#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EP_BulletInfo.generated.h"



UCLASS()
class EXPERIMENTALPROJECT_API UEP_BulletInfo : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		FText Name;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		float Damage;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		float ArmorPenetrationLevel;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		float MaxSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		float GravityScale;
};
