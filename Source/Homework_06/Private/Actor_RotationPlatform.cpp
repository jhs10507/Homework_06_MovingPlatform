#include "Actor_RotationPlatform.h"

AActor_RotationPlatform::AActor_RotationPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT(
		"/Game/Resources/Models/Misc/Moving_Platforms/SM_Moving_Platform_2m_01"
	));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 100.0f;
}

void AActor_RotationPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorRotation(FRotator(0.0f, 1.0f, 0.0f));
}

void AActor_RotationPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
}