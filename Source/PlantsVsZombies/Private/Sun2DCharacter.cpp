// Fill out your copyright notice in the Description page of Project Settings.


#include "Sun2DCharacter.h"
#include "Kismet/KismetMathLibrary.h"

void ASun2DCharacter::SunMoveTick()
{
	auto Position = GetActorLocation();
	if(!bIsFirstMove)
	{
		bIsFirstMove = true;
		Position.Z = 0.;
		TargetDirection = UKismetMathLibrary::GetDirectionUnitVector(Position, TargetPosition);
	}
	AddMovementInput(TargetDirection);
	if(UKismetMathLibrary::NearlyEqual_FloatFloat(Position.X, TargetPosition.X, 10.) &&
		UKismetMathLibrary::NearlyEqual_FloatFloat(Position.Y, TargetPosition.Y, 10.))
	{
		Destroy();
		SunAdd();
	}
}

void ASun2DCharacter::SunFullTick()
{
	AddMovementInput(GetActorRightVector());
}

void ASun2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if(MoveTimer.IsValid())
	{
		GWorld->GetTimerManager().ClearTimer(MoveTimer);
	}
	if (FullTimer.IsValid())
	{
		GWorld->GetTimerManager().ClearTimer(FullTimer);
	}
}

void ASun2DCharacter::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	GWorld->GetTimerManager().SetTimer(MoveTimer, this, &ASun2DCharacter::SunMoveTick, 0.01, true);
}

void ASun2DCharacter::SunAdd_Implementation()
{
}

void ASun2DCharacter::SunFull(bool bIsFull)
{
	if (bIsFull) 
	{
		GWorld->GetTimerManager().SetTimer(FullTimer, this, &ASun2DCharacter::SunFullTick, 0.01, true);
	}
	GWorld->GetTimerManager().ClearTimer(FullTimer);
}
