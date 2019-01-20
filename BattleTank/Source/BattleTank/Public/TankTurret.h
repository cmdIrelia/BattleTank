// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
//hideCategories表示将BP的detail中的某些类进行隐藏。该步骤可选。
//ClassGroup = (Custom),
/* 自定义一个Component，可被蓝图调用 */
UCLASS(meta = (BlueprintSpawnableComponent))//, hideCategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 30;

	//UPROPERTY(EditAnywhere, Category = Setup)
	//	float MaxRotationDegree = 40;

	//UPROPERTY(EditAnywhere, Category = Setup)
	//	float MinRotationDegree = 0;
	
};
