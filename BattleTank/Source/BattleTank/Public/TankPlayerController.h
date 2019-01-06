// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank *GetControlledTank() const;
	
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	//�ƶ��ڹ� ��׼׼��
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	//��UI�еİ׵����λ�þ���
	UPROPERTY(EditAnywhere)
		float CorsshairXLocation = 0.5;
	//��UI�еİ׵����λ�þ���
	UPROPERTY(EditAnywhere)
		float CorsshairYLocation = 0.33333;
};
