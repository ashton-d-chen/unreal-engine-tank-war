// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "../Public/Tank.h"
#include "../Public/TankBarrel.h"
#include "../Public/Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;  // Don't tick to improve efficiency

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* _InputComponent)
{
	Super::SetupPlayerInputComponent(_InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank fires"), Time);

	bool bReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (!bReloaded)
	{
		return;
	}

	LastFireTime = FPlatformTime::Seconds();

	if (!Barrel)
	{
		return;
	}

	// Sapwn a projectile
	auto Location = Barrel->GetSocketLocation(FName("Projectile"));
	auto Rotator = Barrel->GetSocketRotation(FName("Projectile"));
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint, Location, Rotator);

	// Launch projectile
	Projectile->LaunchProjectile(LaunchSpeed);
}

void ATank::setBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->setBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::setTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->setTurretReference(TurretToSet);
}
