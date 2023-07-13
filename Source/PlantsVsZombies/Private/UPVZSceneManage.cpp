#include "UPVZSceneManage.h"

#include "Zombies2DCharacter.h"
#include "Kismet/KismetMathLibrary.h"


FPlantGrid APvzSceneManage::CheckPlantGrid(const FVector& Position) const
{
	FPlantGrid PlantGrid{};

	for (auto i = size_t(); i < std::size(XAxis); ++i) 
	{
		if(UKismetMathLibrary::NearlyEqual_FloatFloat(Position.X, XAxis[i], 40.))
		{
			PlantGrid.X = i;
			break;
		}
	}
	for (auto i = size_t(); i < std::size(YAxis); ++i) {
		if (UKismetMathLibrary::NearlyEqual_FloatFloat(Position.Y, YAxis[i], 50.))
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
	PlantGrid.GridPosition = { XAxis[PlantGrid.X], YAxis[PlantGrid.Y], 10. };
	// 是否长了植物
	if(!GrowPlants[PlantGrid.X][PlantGrid.Y])
	{
		return PlantGrid;
	}

	PlantGrid.IsGrow = true;

	return PlantGrid;
}

void APvzSceneManage::GrowPlant(int X, int Y, APlants2DCharacter* Plants)
{
	GrowPlants[X][Y] = Plants;
}

void APvzSceneManage::RemovePlant(int X, int Y)
{
	GrowPlants[X][Y] = nullptr;
}

void APvzSceneManage::SpawnZombiesType(const TSubclassOf<AZombies2DCharacter> ZombiesPaperZDCharacterClass) const
{
	const auto SpawnYAxis = UKismetMathLibrary::RandomIntegerInRange(0, std::size(YAxis));
	const FVector SpawnPosition{ ZombiesSpawnX, YAxis[SpawnYAxis], 10. };

	if (const AZombies2DCharacter* ZombiesActor = GWorld->SpawnActor<AZombies2DCharacter>(*ZombiesPaperZDCharacterClass,
		SpawnPosition,
		{ 0.,0.,-90. }); ZombiesActor)
	{
	}


}

void APvzSceneManage::SpawnZombies()
{
	if(UKismetMathLibrary::RandomIntegerInRange(0 , 100) >= 60)
		return;

	if(ZombiesPaperZDCharacterClassArray.IsEmpty())
		return;

	const auto ZombiesType = UKismetMathLibrary::RandomIntegerInRange(0, ZombiesPaperZDCharacterClassArray.Num());
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

void APvzSceneManage::BeginPlay()
{
	GWorld->GetTimerManager().SetTimer(SpawnZombiesTimer, this, &APvzSceneManage::SpawnZombies, 5, true);
}

void APvzSceneManage::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GWorld->GetTimerManager().ClearTimer(SpawnZombiesTimer);
}

