// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PlantsBullet2DCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API APlantsBullet2DCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	bool bIsHit = false;

	UFUNCTION(BlueprintCallable, Category = "Bean")
	virtual void SetAttacking(const int PlantAttacking);

	UFUNCTION(BlueprintCallable, Category = "Bean")
	void Move();

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


	/* �¼� */
	UFUNCTION(BlueprintCallable, Category = "Bean")
		void OnHitZombies(AZombies2DCharacter* Zombie);

private:
	/* ���� */
	// ������
	int Attacking = 1;
	
};
