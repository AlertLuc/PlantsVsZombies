// Fill out your copyright notice in the Description page of Project Settings.


#include "Car2DCharacter.h"
#include "Zombies2DCharacter.h"

void ACar2DCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// tick 小车的移动
	if(bIsRun)
	{
		Move();
	}
}

void ACar2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (CarDestroyTimer.IsValid())
	{
		// 清除
		GetWorld()->GetTimerManager().ClearTimer(CarDestroyTimer);
	}
		
	Super::EndPlay(EndPlayReason);
}

void ACar2DCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	// 是否能转成僵尸类
	if(const auto Zombies = Cast<AZombies2DCharacter>(OtherActor))
	{
		bIsRun = true;
		// 僵尸被撞
		Zombies->OnCarCollision();
		if (!CarDestroyTimer.IsValid())
		{
			// 设置小车3秒消失
			GetWorld()->GetTimerManager().SetTimer(CarDestroyTimer, this, &ACar2DCharacter::DestroyCar, 3);
		}
	}
}

void ACar2DCharacter::Move()
{
	// APawn
	AddMovementInput(GetActorForwardVector());
}