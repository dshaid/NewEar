// Fill out your copyright notice in the Description page of Project Settings.


#include "InstanceActorCreate.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
AInstanceActorCreate::AInstanceActorCreate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMesh"));


}

// Called when the game starts or when spawned
void AInstanceActorCreate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


