// Fill out your copyright notice in the Description page of Project Settings.


#include "Sun2DCharacter.h"

#include "PvzFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// 检测太阳移动
void ASun2DCharacter::SunMoveTick()
{

	auto Position = GetActorLocation();
	if(!bIsFirstMove)
	{
		bIsFirstMove = true;
		Position.Z = 0.;
		TargetDirection = UKismetMathLibrary::GetDirectionUnitVector(Position, TargetPosition);
	}

	// 太阳落下速度
	UPvzFunctionLibrary::MoveActor(this, TargetDirection, 7.5);

	if(UKismetMathLibrary::NearlyEqual_FloatFloat(Position.X, TargetPosition.X, 10.) &&
		UKismetMathLibrary::NearlyEqual_FloatFloat(Position.Y, TargetPosition.Y, 10.))
	{
		// 销毁并增加
		Destroy();
		SunAdd();
	}
}

// 阳光落下检测
void ASun2DCharacter::SunFullTick()
{
	UPvzFunctionLibrary::MoveActor(this, GetActorUpVector(), -0.6);
}


void ASun2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	// 清除定时器
	if(MoveTimer.IsValid())
	{
		GWorld->GetTimerManager().ClearTimer(MoveTimer);
	}
	if (FullTimer.IsValid())
	{
		GWorld->GetTimerManager().ClearTimer(FullTimer);
	}
}

// 鼠标碰撞到太阳
void ASun2DCharacter::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	GWorld->GetTimerManager().SetTimer(MoveTimer, this, &ASun2DCharacter::SunMoveTick, 0.01, true);
}

// 太阳落下
void ASun2DCharacter::SunFull(bool bIsFull)
{
	if (bIsFull) 
	{
		// 设置太阳落下的速度
		GWorld->GetTimerManager().SetTimer(FullTimer, this, &ASun2DCharacter::SunFullTick, 0.01, true);
	}
	GWorld->GetTimerManager().ClearTimer(FullTimer);
}
