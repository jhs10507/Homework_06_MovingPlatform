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
}

void AActor_MovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(0.0f, 0.0f, 0.0f));
	StartLocation = FVector(0.0f, 0.0f, 0.0f);
	CurrentLocation = FVector(10.0f, 0.0f, 0.0f);
	MoveSpeed = 10.0f;
	MaxRange = 300.0f;
}

void AActor_MovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector Velocity = CurrentLocation.GetSafeNormal() * MoveSpeed;
	AddActorLocalOffset((CurrentLocation.GetSafeNormal() * MoveSpeed) *DeltaTime);

	/*float Speed = 100;
	FVector Direction = FVector(1, 1, 0);
	FVector Velocity = Direction.GetSafeNormal() * Speed;

	/*FVector Velocity = FVector(100,0,0); 
	AddActorLocalOffset(Velocity * DeltaTime);*/

	//AddActorLocalOffset((StartLocation + CurrentLocation.X) + (MoveSpeed * DeltaTime));
}