// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
//�������һ��UCLASS�ġ�meta�����ԣ�BP����add component�����TankBarrel��
//hideCategories��ʾ��BP��detail�е�ĳЩ��������ء��ò����ѡ��
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
