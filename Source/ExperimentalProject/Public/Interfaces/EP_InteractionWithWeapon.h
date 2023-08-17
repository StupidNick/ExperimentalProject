#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Weapons/Magazines/EP_BaseMagazine.h"
#include "EP_InteractionWithWeapon.generated.h"



class UEP_EquipmentComponent;



// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEP_InteractionWithWeapon : public UInterface
{
	GENERATED_BODY()
};



class EXPERIMENTALPROJECT_API IEP_InteractionWithWeapon
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Shooting")
		bool DoShot();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Reloading")
		bool DoReload(float SkillFactor, float AdditionalReloadTime, AEP_BaseMagazine* NewAttachedMagazine);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Reloading")
		void DoCheckAmmo(UEP_EquipmentComponent* EquipmentComponent);
};
