#include "ExperimentalProject/Public/Characters/EP_BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"



AEP_BaseCharacter::AEP_BaseCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create a equipment component
	EquipmentComponent = CreateDefaultSubobject<UEP_EquipmentComponent>("EquipmentComponent");
}

void AEP_BaseCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

//////////////////////////////////////////////////////////////////////////// Input

void AEP_BaseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Repeat, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, EquipmentComponent, &UEP_EquipmentComponent::StartFire);
	
	PlayerInputComponent->BindAction("Reload", IE_Released, EquipmentComponent, &UEP_EquipmentComponent::SlowReloadWeapon);
	PlayerInputComponent->BindAction("Reload", IE_DoubleClick, EquipmentComponent, &UEP_EquipmentComponent::QuickReloadWeapon);

	// Bind movement events
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AEP_BaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AEP_BaseCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "Mouse" versions handle devices that provide an absolute delta, such as a mouse.
	// "Gamepad" versions are for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
}

void AEP_BaseCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AEP_BaseCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}