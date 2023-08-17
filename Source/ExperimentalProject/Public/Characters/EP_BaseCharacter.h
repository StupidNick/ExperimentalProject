// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExperimentalProject/Public/Components/EP_EquipmentComponent.h"
#include "GameFramework/Character.h"
#include "EP_BaseCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;



UCLASS(config=Game)
class AEP_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

public:
	AEP_BaseCharacter();

protected:
	virtual void BeginPlay();
	
	void MoveForward(float Val);
	void MoveRight(float Val);
	
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UEP_EquipmentComponent* EquipmentComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		FName WeaponSocketName;
};

