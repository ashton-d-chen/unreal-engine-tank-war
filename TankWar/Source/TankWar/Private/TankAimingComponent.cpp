// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "../Public/TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::setBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::setTurretReference(UStaticMeshComponent* TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	auto TankName = GetOwner()->GetName();
//	auto BarrelLocation = Barrel->GetComponentLocation().ToString();
//	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *TankName, *HitLocation.ToString(), *BarrelLocation);


	FVector OutLaunchVelocity;  // use to store launch velocity
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool success = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace

	);

	// if there is a solution found
	if (success)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s firing at %s"), *TankName, *AimDirection.ToString());

		MoveBarrel(AimDirection);
	}


}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	// Work out difference between barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	UE_LOG(LogTemp, Warning, TEXT("AimRotator: %s"), *AimRotator.ToString());

	auto DeltaRotator = AimRotator - BarrelRotator;
	
	
	// Move the barrel the right amount this frame
	Barrel->Elevate(5);

	// Given a max elevation speed, and the 
}
