// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TankAimingComponent.h"

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = SetupLaLa)
	void SetBarrelReference(UTankBarrel *BarrelToSet);

	
	UFUNCTION(BlueprintCallable, Category = SetupLaLa)
	void SetTurretReference(UTankTurret *TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Fire)
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UTankAimingComponent *TankAimingComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
