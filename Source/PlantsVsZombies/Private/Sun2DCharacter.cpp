// Fill out your copyright notice in the Description page of Project Settings.


#include "Sun2DCharacter.h"

#include "PvzFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// ���̫���ƶ�
void ASun2DCharacter::SunMoveTick()
{

	auto Position = GetActorLocation();
	if(!bIsFirstMove)
	{
		bIsFirstMove = true;
		Position.Z = 0.;
		TargetDirection = UKismetMathLibrary::GetDirectionUnitVector(Position, TargetPosition);
	}

	// ̫�������ٶ�
	UPvzFunctionLibrary::MoveActor(this, TargetDirection, 7.5);

	if(UKismetMathLibrary::NearlyEqual_FloatFloat(Position.X, TargetPosition.X, 10.) &&
		UKismetMathLibrary::NearlyEqual_FloatFloat(Position.Y, TargetPosition.Y, 10.))
	{
		// ���ٲ�����
		Destroy();
		SunAdd();
	}
}

// �������¼��
void ASun2DCharacter::SunFullTick()
{
	UPvzFunctionLibrary::MoveActor(this, GetActorUpVector(), -0.6);
}


void ASun2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	// �����ʱ��
	if(MoveTimer.IsValid())
	{
		GWorld->GetTimerManager().ClearTimer(MoveTimer);
	}
	if (FullTimer.IsValid())
	{
		GWorld->GetTimerManager().ClearTimer(FullTimer);
	}
}

// �����ײ��̫��
void ASun2DCharacter::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	GWorld->GetTimerManager().SetTimer(MoveTimer, this, &ASun2DCharacter::SunMoveTick, 0.01, true);
}

// ̫������
void ASun2DCharacter::SunFull(bool bIsFull)
{
	if (bIsFull) 
	{
		// ����̫�����µ��ٶ�
		GWorld->GetTimerManager().SetTimer(FullTimer, this, &ASun2DCharacter::SunFullTick, 0.01, true);
	}
	GWorld->GetTimerManager().ClearTimer(FullTimer);
}
