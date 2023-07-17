// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Car2DCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API ACar2DCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	bool bIsRun = false;

	// 重写函数 继承游戏引擎actor类
	virtual void Tick(float DeltaSeconds) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// 碰撞检测
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	// 移动
	UFUNCTION(BlueprintCallable)
	void Move();

	// 销毁
	void DestroyCar()
	{
		Destroy();
	}

private:
	/* 定时器 */
	FTimerHandle CarDestroyTimer;
};
