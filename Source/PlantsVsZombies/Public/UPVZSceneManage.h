﻿#pragma once
#include "CoreMinimal.h"
#include "UPVZSceneManage.generated.h"

class AZombies2DCharacter;
class APlants2DCharacter;

USTRUCT(BlueprintType)
struct FPlantGrid
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	APlants2DCharacter* Plants = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int X = -1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Y = -1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsGrow = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector GridPosition {};
};


UCLASS(BlueprintType, Blueprintable)
class APvzSceneManage : public AActor
{
	GENERATED_BODY()
public:
	TArray<TSubclassOf<AZombies2DCharacter>> ZombiesPaperZDCharacterClassArray;

	UFUNCTION(BlueprintCallable)
	FPlantGrid CheckPlantGrid(const FVector& Position)const;

	UFUNCTION(BlueprintCallable)
	void GrowPlant(int X, int Y, APlants2DCharacter* Plants);

	UFUNCTION(BlueprintCallable)
	void RemovePlant(int X, int Y);

	UFUNCTION(BlueprintCallable)
	void RemoveZombies(int Y);

	UFUNCTION(BlueprintCallable)
	void SpawnZombiesType(const TSubclassOf<AZombies2DCharacter> ZombiesPaperZDCharacterClass);

	UFUNCTION(BlueprintCallable)
	void SpawnZombies();

	UFUNCTION(BlueprintCallable)
	static APvzSceneManage* GetInstance();

	UFUNCTION(BlueprintCallable)
	void OnBegin(const TArray<TSubclassOf<AZombies2DCharacter>>& ZombiesClassArray);

	UFUNCTION(BlueprintCallable)
	void OnEnd();

private:

	FTimerHandle SpawnZombiesTimer{};

	const double XGrid[9] = {
	-410., -330., -250., -170., -90., -10., 70., 150., 230.
	};
	const double GridY[5] = {
		-160., -60., 40., 140., 240.
	};

	APlants2DCharacter* GrowPlants[9][5];
	int ZombiesNum[5];

	const double ZombiesSpawnGridX = 420.;
};
