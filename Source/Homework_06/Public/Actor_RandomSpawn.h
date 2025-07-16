#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_RandomSpawn.generated.h"

UCLASS()
class HOMEWORK_06_API AActor_RandomSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	AActor_RandomSpawn();

protected:
	virtual void BeginPlay() override;

	TArray<FVector> GenerateRandomLocations();

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FInt32Point GridSize;

	UPROPERTY(EditAnywhere)
	int SpawnCount;

	UPROPERTY(EditAnywhere)
	float SpawnOffset;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> ActorClassToSpawn;
};
