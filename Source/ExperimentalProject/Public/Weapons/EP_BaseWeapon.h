#pragma once

#include "CoreMinimal.h"
#include "Data/EP_WeaponData.h"
#include "ExperimentalProject/Public/Interfaces/EP_InteractionWithWeapon.h"
#include "GameFramework/Actor.h"
#include "EP_BaseWeapon.generated.h"



UCLASS()
class EXPERIMENTALPROJECT_API AEP_BaseWeapon : public AActor, public IEP_InteractionWithWeapon
{
	GENERATED_BODY()
	
public:	
	
	AEP_BaseWeapon();

	virtual bool DoReload_Implementation(float SkillFactor, float AdditionalReloadTime, AEP_BaseMagazine* NewAttachedMagazine) override;
	virtual bool DoShot_Implementation() override;

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION()
		virtual bool CanShoot();

	UFUNCTION()
		virtual void Shot();

	UFUNCTION()
		virtual void Reload(float SkillFactor, float AdditionalReloadTime, AEP_BaseMagazine* NewAttachedMagazine);

protected:

	UPROPERTY()
		float NextShootTime;

public:

	UPROPERTY(EditDefaultsOnly, Category = "Data")
		UEP_WeaponData* WeaponInfo;

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
		USkeletalMeshComponent* Mesh;
};
