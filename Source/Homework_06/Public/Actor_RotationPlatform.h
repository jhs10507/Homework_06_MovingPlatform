#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_RotationPlatform.generated.h"

UCLASS()
class HOMEWORK_06_API AActor_RotationPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AActor_RotationPlatform();

protected:
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float RotationSpeed = 100.0f;

private:	
	virtual void Tick(float DeltaTime) override;
};