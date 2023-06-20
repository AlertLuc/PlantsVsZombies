// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "ProjectileMovementComponent.generated.h"
#include "PlantsBullet.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API APlantsBullet : public APaperSpriteActor
{
	GENERATED_BODY()

public:


	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* ProjectileMovementComponent;


	UFUNCTION(BlueprintCallable, Category = "PlantBullet")
	virtual void SetAttacking(const int PlantAttacking);


	/* ��д���� */

	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


	/* �¼� */

	UFUNCTION(BlueprintCallable, Category = "PlantBullet")
	void OnHitZombies(AZombies2DCharacter* Zombie);

private:


	/* ���� */

	// ������
	int Attacking = 1;
};
