#include "UPVZSceneManage.h"

#include "Plants2DCharacter.h"
#include "Zombies2DCharacter.h"
#include "Kismet/KismetMathLibrary.h"


FPlantGrid APvzSceneManage::CheckPlantGrid(const FVector& Position) const
{
	FPlantGrid PlantGrid{};

	for (auto i = size_t(); i < std::size(XGrid); ++i) 
	{
		if(UKismetMathLibrary::NearlyEqual_FloatFloat(Position.X, XGrid[i], 40.))
		{
			PlantGrid.X = i;
			break;
		}
	}
	for (auto i = size_t(); i < std::size(GridY); ++i) {
		if (UKismetMathLibrary::NearlyEqual_FloatFloat(Position.Y, GridY[i], 50.))
		{
			PlantGrid.Y = i;
			break;
		}
	}
	// 不在格子里
	if (PlantGrid.X == -1 || PlantGrid.Y == -1)
	{
		return PlantGrid;
	}
	PlantGrid.GridPosition = { XGrid[PlantGrid.X], GridY[PlantGrid.Y], 10. };
	// 是否长了植物
	if(PlantGrid.Plants = GrowPlants[PlantGrid.X][PlantGrid.Y]; !PlantGrid.Plants)
	{
		return PlantGrid;
	}

	PlantGrid.IsGrow = true;

	return PlantGrid;
}

void APvzSceneManage::GrowPlant(int X, int Y, APlants2DCharacter* Plants)
{
	GrowPlants[X][Y] = Plants;
	Plants->HandleCanAttackZombies(ZombiesNum[Y] > 0);
}

void APvzSceneManage::RemovePlant(int X, int Y)
{
	GrowPlants[X][Y] = nullptr;
}

void APvzSceneManage::RemoveZombies(int Y)
{
	auto& ZombiesY = ZombiesNum[Y];

	if (ZombiesY > 0 && Y != -1) 
	{
		ZombiesY--;
	}
	if (ZombiesY <= 0)
	{
		for (auto i = 0; i < 9; i++)
		{
			if (auto* GrowPlant = GrowPlants[i][Y]; GrowPlant)
				GrowPlant->HandleCanAttackZombies(false);
		}
	}
}

void APvzSceneManage::SpawnZombiesType(const TSubclassOf<AZombies2DCharacter> ZombiesPaperZDCharacterClass)
{
	const auto SpawnGridY = UKismetMathLibrary::RandomIntegerInRange(0, std::size(GridY) - 1);
	const FVector SpawnPosition{ ZombiesSpawnGridX, GridY[SpawnGridY], 10. };

	if (AZombies2DCharacter* ZombiesActor = GWorld->SpawnActor<AZombies2DCharacter>(*ZombiesPaperZDCharacterClass,
		SpawnPosition,
		{ 0.,0.,-90. }); ZombiesActor)
	{
		ZombiesActor->SetGridY(SpawnGridY);
		ZombiesNum[SpawnGridY]++;
		for (auto i = 0; i < 9; i++)
		{
			if (auto* GrowPlant = GrowPlants[i][SpawnGridY]; GrowPlant)
				GrowPlant->HandleCanAttackZombies(true);
		}
	}
}

void APvzSceneManage::SpawnZombies()
{
	if(UKismetMathLibrary::RandomIntegerInRange(0 , 100) >= 60)
		return;

	if(ZombiesPaperZDCharacterClassArray.IsEmpty())
		return;

	const auto ZombiesType = UKismetMathLibrary::RandomIntegerInRange(0, ZombiesPaperZDCharacterClassArray.Num() - 1);
	SpawnZombiesType(ZombiesPaperZDCharacterClassArray[ZombiesType]);
}

APvzSceneManage* APvzSceneManage::GetInstance() {
	if (GEngine)
	{
		APvzSceneManage* Instance = Cast<APvzSceneManage>(GEngine->GameSingleton);
		return Instance;
	}
	return nullptr;
}

void APvzSceneManage::OnBegin(const TArray<TSubclassOf<AZombies2DCharacter>>& ZombiesClassArray)
{
	memset(GrowPlants, 0, sizeof GrowPlants);
	memset(ZombiesNum, 0, sizeof ZombiesNum);
	ZombiesPaperZDCharacterClassArray = ZombiesClassArray;
	GWorld->GetTimerManager().SetTimer(SpawnZombiesTimer, this, &APvzSceneManage::SpawnZombies, 10, true);
}

void APvzSceneManage::OnEnd()
{
	GWorld->GetTimerManager().ClearTimer(SpawnZombiesTimer);
}

