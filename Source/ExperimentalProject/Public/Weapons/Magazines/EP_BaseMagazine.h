#pragma once

#include "CoreMinimal.h"
#include "Data/EP_AmmoInfo.h"
#include "Data/EP_MagazineData.h"
#include "GameFramework/Actor.h"
#include "Interfaces/EP_InventoryItemInteraction.h"
#include "EP_BaseMagazine.generated.h"



UCLASS()
class EXPERIMENTALPROJECT_API AEP_BaseMagazine : public AActor, public IEP_InventoryItemInteraction
{
	GENERATED_BODY()
	
public:	
	
	AEP_BaseMagazine();

	UFUNCTION()
		bool AddBulletToMagazine(UEP_AmmoInfo* inBulletInfo);

	UFUNCTION()
		UEP_AmmoInfo* GetTopBullet() const;

	UFUNCTION()
		void RemoveTopBullet();

	UFUNCTION()
		int GetBulletCount() const;

	UFUNCTION()
		virtual float GetSlotVolume_Implementation() override;

protected:
	
	virtual void BeginPlay() override;

	TDoubleLinkedList<UEP_AmmoInfo*> BulletStack;

public:

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
		UEP_MagazineData* MagazineInfo;
};
