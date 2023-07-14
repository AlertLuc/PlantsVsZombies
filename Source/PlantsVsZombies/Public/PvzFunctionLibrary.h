// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PvzFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API UPvzFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void MoveActor(AActor* Actor, FVector Direction, double Speed);
};
