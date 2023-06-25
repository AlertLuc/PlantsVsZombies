// Fill out your copyright notice in the Description page of Project Settings.


#include "Car2DCharacter.h"
#include "Zombies2DCharacter.h"

void ACar2DCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(bIsRun)
	{
		Move();
	}
}

void ACar2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (CarDestroyTimer.IsValid())
		GetWorld()->GetTimerManager().ClearTimer(CarDestroyTimer);
	Super::EndPlay(EndPlayReason);
}

void ACar2DCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if(const auto Zombies = Cast<AZombies2DCharacter>(OtherActor))
	{
		bIsRun = true;
		Zombies->OnCarCollision();
		if (!CarDestroyTimer.IsValid()) {
			GetWorld()->GetTimerManager().SetTimer(CarDestroyTimer, this, &ACar2DCharacter::DestroyCar, 3);
		}
	}
}

void ACar2DCharacter::Move()
{
	AddMovementInput(GetActorForwardVector());
}