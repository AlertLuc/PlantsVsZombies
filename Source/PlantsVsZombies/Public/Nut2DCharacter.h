// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plants2DCharacter.h"
#include "Nut2DCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API ANut2DCharacter : public APlants2DCharacter
{
	GENERATED_BODY()

public:
	// 坚果生命值
	ANut2DCharacter()
	{
		Health = 100;
	}
};
