#include "Actor_MovingPlatform.h"

AActor_MovingPlatform::AActor_MovingPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT(
		"/Game/Resources/Models/Misc/Moving_Platforms/SM_Moving_Platform_1m_01"
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
	MoveSpeed = 100.0f;
	bMovingForward = true;
}

void AActor_MovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = StartLocation + TargetOffset;
}

void AActor_MovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentLocation = GetActorLocation();
	Direction = bMovingForward ? (EndLocation - StartLocation).GetSafeNormal() : 
		(StartLocation - EndLocation).GetSafeNormal();
	float Distance = MoveSpeed * DeltaTime;

	CurrentLocation += Direction * Distance;
	SetActorLocation(CurrentLocation);

	if (bMovingForward && FVector::Dist(CurrentLocation, EndLocation) < 1.0f)
	{
		bMovingForward = false;
		//UE_LOG(LogTemp, Warning, TEXT("전진"));
	}
	else if (!bMovingForward && FVector::Dist(CurrentLocation, StartLocation) < 1.0f)
	{
		bMovingForward = true;
		//UE_LOG(LogTemp, Warning, TEXT("후진"));
	}
}