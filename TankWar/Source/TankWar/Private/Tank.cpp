// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "../Public/Tank.h"


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

}

void ATank::setBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->setBarrelReference(BarrelToSet);
}

void ATank::setTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->setTurretReference(TurretToSet);
}
