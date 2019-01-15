// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
//添加了这一行UCLASS的【meta】属性，BP里面add component会出现TankBarrel。
//hideCategories表示将BP的detail中的某些类进行隐藏。该步骤可选。
//ClassGroup = (Custom),
UCLASS(meta = (BlueprintSpawnableComponent), hideCategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegree = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegree = 0;

	
};
