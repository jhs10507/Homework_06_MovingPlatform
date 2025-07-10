#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_MovingPlatform.generated.h"

UCLASS()
class HOMEWORK_06_API AActor_MovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AActor_MovingPlatform();

protected:
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	FVector StartLocation, CurrentLocation;
	float MoveSpeed = 0.0f;
	float MaxRange = 0.0f;

private:	
	virtual void Tick(float DeltaTime) override;
};
