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

	FVector StartLocation = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	FVector CurrentLocation = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	FVector EndLocation = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	FVector MaxRange = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	FVector Direction = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	FVector TargetOffset = FVector(300.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	float MoveSpeed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	bool bMovingForward = true;

private:	
	virtual void Tick(float DeltaTime) override;
};