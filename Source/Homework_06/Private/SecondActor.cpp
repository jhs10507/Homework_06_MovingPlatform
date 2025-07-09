// Fill out your copyright notice in the Description page of Project Settings.


#include "SecondActor.h"

// Sets default values
ASecondActor::ASecondActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASecondActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASecondActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

