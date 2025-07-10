#include "Actor_MovingPlatform.h"


AActor_MovingPlatform::AActor_MovingPlatform()
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

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT(
		"/Game/Resources/Materials/Color_02/MI_Moving_Platform_Clr_02.MI_Moving_Platform_Clr_02"
	));
	if (MaterialAsset.Succeeded())
	{
		UMaterialInterface* CurrentMaterial = StaticMeshComp->GetMaterial(0);
		if (CurrentMaterial != MaterialAsset.Object)
		{
			StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
		}
	}

	PrimaryActorTick.bCanEverTick = true;

	//StartLocation(FVector(0.0f, 0.0f, 0.0f));
}

void AActor_MovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

void AActor_MovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//AddActorLocalOffset();
}

