// Fill out your copyright notice in the Description page of Project Settings.


#include "PvzFunctionLibrary.h"

void UPvzFunctionLibrary::MoveActor(AActor* Actor, FVector Direction, double Speed)
{
	Actor->SetActorLocation(Actor->GetActorLocation() + Direction.GetSafeNormal() * Speed);
}
