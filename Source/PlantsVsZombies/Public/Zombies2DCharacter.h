// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Zombies2DCharacter.generated.h"

class Plants2DCharacter;

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API AZombies2DCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:


	/* 属性 */

	// 生命值
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int Health = 10;

	// 移动速度
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int MoveSpeed = 10;

	// 攻击力
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int Attacking = 1;

	// 攻击速度
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int AttackSpeed = 4;


	/* 重写函数 */

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;


	/* 事件 */

	UFUNCTION(BlueprintImplementableEvent, Category = "Zombies")
	void OnZombiesEat(bool IsEat);

	UFUNCTION(BlueprintImplementableEvent, Category = "Zombies")
	void OnZombiesDie(bool IsDie);

	UFUNCTION(BlueprintCallable, Category = "Zombies")
	void OnZombiesOverlapPlants(APlants2DCharacter* Plants2DCharacter, bool Overlap);

	void HandlePlantsAttack(int PlantsAttacking);

	/* 定时事件 */

	void TickZombiesEat() const;


	/* 方法 */

	UFUNCTION(BlueprintCallable, Category = "Zombies")
	void Move();

private:


	/* 事件声明 */

	DECLARE_EVENT_OneParam(AZombies2DCharacter, ZombiesEat, int)
	ZombiesEat ZombiesEatEvent;


	/* 定时器 */

	FTimerHandle TickZombiesEatTimer;


	/* 内部状态 */

	bool bZombiesOverlapPlants = false;
};
