#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Data/EP_BulletInfo.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "EP_BaseProjectile.generated.h"


class UEP_AmmoInfo;



UCLASS()
class EXPERIMENTALPROJECT_API AEP_BaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AEP_BaseProjectile();

	UFUNCTION()
		virtual void InitializeProjectile();

protected:
	
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UProjectileMovementComponent* ProjectileComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		USphereComponent* Collision;

	UPROPERTY(EditDefaultsOnly, Category = "Info")
		UEP_BulletInfo* BulletInfo;
};
