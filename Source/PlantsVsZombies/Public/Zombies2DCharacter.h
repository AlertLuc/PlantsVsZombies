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


	/* ���� */

	// ����ֵ
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int Health = 10;

	// �ƶ��ٶ�
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int MoveSpeed = 10;

	// ������
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int Attacking = 1;

	// �����ٶ�
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int AttackSpeed = 4;


	/* ��д���� */

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;


	/* �¼� */

	UFUNCTION(BlueprintImplementableEvent, Category = "Zombies")
	void OnZombiesEat(bool IsEat);

	UFUNCTION(BlueprintImplementableEvent, Category = "Zombies")
	void OnZombiesDie(bool IsDie);

	UFUNCTION(BlueprintCallable, Category = "Zombies")
	void OnZombiesOverlapPlants(APlants2DCharacter* Plants2DCharacter, bool Overlap);

	void HandlePlantsAttack(int PlantsAttacking);

	/* ��ʱ�¼� */

	void TickZombiesEat() const;


	/* ���� */

	UFUNCTION(BlueprintCallable, Category = "Zombies")
	void Move();

private:


	/* �¼����� */

	DECLARE_EVENT_OneParam(AZombies2DCharacter, ZombiesEat, int)
	ZombiesEat ZombiesEatEvent;


	/* ��ʱ�� */

	FTimerHandle TickZombiesEatTimer;


	/* �ڲ�״̬ */

	bool bZombiesOverlapPlants = false;
};
