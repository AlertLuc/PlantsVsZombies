// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plants2DCharacter.h"
#include "PlantsBullet2DCharacter.h"
#include "Pea2DCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API APea2DCharacter : public APlants2DCharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<APlantsBullet2DCharacter> BeanPaperZDCharacterClass{};

	virtual void OnPlantsAttacking_Implementation() override;
};
