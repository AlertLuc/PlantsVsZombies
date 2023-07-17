// Fill out your copyright notice in the Description page of Project Settings.


#include "Car2DCharacter.h"
#include "Zombies2DCharacter.h"

void ACar2DCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// tick С�����ƶ�
	if(bIsRun)
	{
		Move();
	}
}

void ACar2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (CarDestroyTimer.IsValid())
	{
		// ���
		GetWorld()->GetTimerManager().ClearTimer(CarDestroyTimer);
	}
		
	Super::EndPlay(EndPlayReason);
}

void ACar2DCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	// �Ƿ���ת�ɽ�ʬ��
	if(const auto Zombies = Cast<AZombies2DCharacter>(OtherActor))
	{
		bIsRun = true;
		// ��ʬ��ײ
		Zombies->OnCarCollision();
		if (!CarDestroyTimer.IsValid())
		{
			// ����С��3����ʧ
			GetWorld()->GetTimerManager().SetTimer(CarDestroyTimer, this, &ACar2DCharacter::DestroyCar, 3);
		}
	}
}

void ACar2DCharacter::Move()
{
	// APawn
	AddMovementInput(GetActorForwardVector());
}