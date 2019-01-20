// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include <Kismet/GameplayStatics.h>

#include <DrawDebugHelpers.h>

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet)
{
	if (!BarrelToSet) return;
	this->Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret *TurretToSet)
{
	if (!TurretToSet) return;
	this->Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector outLaunchVelocity;
	FVector startLocation = Barrel->GetSocketLocation(FName("Projectile"));	

	bool bHaveAimingSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		outLaunchVelocity,
		startLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimingSolution)
	{
		auto aimDirection = outLaunchVelocity.GetSafeNormal();	//归一化
		//auto name = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s startLoc=%s Speed=%s"), *name, *startLocation.ToString(), *AimDirection.ToString());
		MoveBarrelTowards(aimDirection);  

		//绘制弹着点
		DrawDebugSphere(
			GetWorld(),
			HitLocation,
			24,
			32,
			FColor(255, 0, 0)
		);

		//绘制炮管延伸线
		FRotator rot(Barrel->GetForwardVector().Rotation());
		DrawDebugLine(
			GetWorld(),
			startLocation,
			startLocation + rot.RotateVector(FVector(500000, 0, 0)),
			FColor(255, 0, 0)
		);
	}
	else
	{
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: TankAimingComponent found no solution"), time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//计算瞄准点与炮管指向之间的角度差值
	auto barrelRotation = Barrel->GetForwardVector().Rotation();//获得往前指向的轴，X轴
	auto aimAsRotation = AimDirection.Rotation();
	auto deltaRotator = aimAsRotation - barrelRotation;

	//Barrel->Elevate(1);
	Barrel->Elevate(deltaRotator.Pitch);

	Turret->Rotate(deltaRotator.Yaw);
}
