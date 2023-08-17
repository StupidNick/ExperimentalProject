#include "ExperimentalProject/Public/Weapons/RangeWeapon/Projectiles/EP_BaseProjectile.h"



AEP_BaseProjectile::AEP_BaseProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	Collision = CreateDefaultSubobject<USphereComponent>("Collision");
	Mesh->SetupAttachment(Collision);
	RootComponent = Collision;

	ProjectileComponent->SetUpdatedComponent(Collision);
	ProjectileComponent->InitialSpeed = 1000.0f;
	ProjectileComponent->MaxSpeed = 1000.0f;
	ProjectileComponent->bRotationFollowsVelocity = true;
	ProjectileComponent->bShouldBounce = false;
	// ProjectileComponent->Bounciness = 0.3f;
	ProjectileComponent->ProjectileGravityScale = 0.0f;
}


void AEP_BaseProjectile::InitializeProjectile()
{
	ProjectileComponent->MaxSpeed = BulletInfo->MaxSpeed;
	ProjectileComponent->InitialSpeed = BulletInfo->MaxSpeed;
	ProjectileComponent->ProjectileGravityScale = BulletInfo->GravityScale;
}


void AEP_BaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}
