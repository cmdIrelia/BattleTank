// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet)
{
	this->Barrel = BarrelToSet;
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
		auto aimDirection = outLaunchVelocity.GetSafeNormal();	//��һ��
		//auto name = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s startLoc=%s Speed=%s"), *name, *startLocation.ToString(), *AimDirection.ToString());
		MoveBarrelTowards(aimDirection);  
	}
	else
	{
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: TankAimingComponent found no solution"), time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//������׼�����ڹ�ָ��֮��ĽǶȲ�ֵ
	auto barrelRotation = Barrel->GetForwardVector().Rotation();//�����ǰָ����ᣬX��
	auto aimAsRotation = AimDirection.Rotation();
	auto deltaRotator = aimAsRotation - barrelRotation;

	//�趨һ��ת�������ֵ
	Barrel->Elevate(5);

}
