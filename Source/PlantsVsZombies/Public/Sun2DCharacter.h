// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Sun2DCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API ASun2DCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

	void SunMoveTick();
	void SunFullTick();

public:

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;

	UFUNCTION(BlueprintNativeEvent)
	void SunAdd();

	void SunAdd_Implementation();

	UFUNCTION(BlueprintCallable)
	void SunFull(bool bIsFull);

private:
	bool bIsFirstMove = false;
	FVector TargetDirection{};
	const FVector TargetPosition{ -480.,-220.,0. };

	FTimerHandle MoveTimer{};
	FTimerHandle FullTimer{};
};
