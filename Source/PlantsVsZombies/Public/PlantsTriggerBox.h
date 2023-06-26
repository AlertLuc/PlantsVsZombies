// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PlantsTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API APlantsTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		int HaveZombiesNum = 0;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		int HavePlantsNum = 0;

	/* 重写函数 */

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;


	/* 事件 */
	void NotifyPlants() const;

	void NotifyZombies() const;
private:


	/* 事件声明 */

	DECLARE_EVENT_OneParam(APlants2DCharacter, CanAttackZombies, bool)
	CanAttackZombies CanAttackZombiesEvent;

	DECLARE_EVENT_OneParam(AZombies2DCharacter, CanAttackPlants, bool)
	CanAttackPlants CanAttackPlantsEvent;
};


