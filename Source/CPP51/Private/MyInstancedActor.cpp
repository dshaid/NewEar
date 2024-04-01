// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInstancedActor.h"

// Sets default values
AMyInstancedActor::AMyInstancedActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyInstancedActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyInstancedActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

