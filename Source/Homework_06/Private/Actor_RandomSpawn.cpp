#include "Actor_RandomSpawn.h"
#include "Actor_MovingPlatform.h"
#include "Actor_RotationPlatform.h"

AActor_RandomSpawn::AActor_RandomSpawn()
{
	PrimaryActorTick.bCanEverTick = true;

	GridSize = FIntPoint(1, 1);
	SpawnCount = 1;
	SpawnOffset = 500.f;
}

void AActor_RandomSpawn::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<FVector> Locations = GenerateRandomLocations();

	if (ActorClassToSpawn.Num() == 0 || Locations.Num() == 0)
	{
		return;
	}

	int ActualSpawncCount = FMath::Min(SpawnCount, Locations.Num());

	for (size_t i = 0; i < SpawnCount; i++)
	{
		int LocationIndex = FMath::RandRange(0, Locations.Num() - 1);

		// 랜덤한 위치 하나를 빼옴.
		FVector SpawnLocation = Locations[LocationIndex];
		SpawnLocation += GetActorLocation();

		// 랜덤한 액터 클래스를 빼옴.
		int ActorIndex = FMath::RandRange(0, ActorClassToSpawn.Num() - 1);

		AActor* SpawnActor = GetWorld()->SpawnActor<AActor>(
			ActorClassToSpawn[ActorIndex],
			SpawnLocation,
			FRotator::ZeroRotator
		);

		if (AActor_MovingPlatform* MovementActor = Cast<AActor_MovingPlatform>(SpawnActor))
		{
			MovementActor->MoveSpeed = FMath::RandRange(100.f, 300.f);
			MovementActor->MaxRange.X = FMath::RandRange(100.f, 300.f);
			MovementActor->MaxRange.Y = FMath::RandRange(100.f, 300.f);
			MovementActor->MaxRange.Z = FMath::RandRange(100.f, 300.f);
		}
		else if (AActor_RotationPlatform* RotatorActor = Cast<AActor_RotationPlatform>(SpawnActor))
		{
			RotatorActor->SetActorRotation(FRotator(FMath::RandRange(100.f, 300.f)));
		}

		float YawRot = FMath::RandRange(0.0f, 360.f);
		SpawnActor->SetActorRotation(FRotator(0.0f, YawRot, 0.0f));

		Locations.RemoveAt(LocationIndex);
	}
}

// 랜덤한 위치를 뽑기 위한 함수
TArray<FVector> AActor_RandomSpawn::GenerateRandomLocations()
{
	TArray<FVector> Locations;

	for (size_t Row = 0; Row < GridSize.X; ++Row)
	{
		for (size_t Column = 0; Column < GridSize.Y; ++Column)
		{
			float X = Row * SpawnOffset;
			float Y = Column * SpawnOffset;

			Locations.Add(FVector(X, Y, GetActorLocation().Z));
		}
	}

	return Locations;
}

void AActor_RandomSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}