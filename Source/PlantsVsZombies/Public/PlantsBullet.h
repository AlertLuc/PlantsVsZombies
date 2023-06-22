// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
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

	APlantsBullet() : ProjectileMovementComponent(CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent")))
	{
		ProjectileMovementComponent->InitialSpeed = 100;
	}


	UFUNCTION(BlueprintCallable, Category = "PlantBullet")
	virtual void SetAttacking(const int PlantAttacking);


	/* 重写函数 */

	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


	/* 事件 */

	UFUNCTION(BlueprintCallable, Category = "PlantBullet")
	void OnHitZombies(AZombies2DCharacter* Zombie);

private:


	/* 属性 */

	// 攻击力
	int Attacking = 1;
};
