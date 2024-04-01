// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InstanceActorCreate.generated.h"

UCLASS()
class CPP51_API AInstanceActorCreate : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInstanceActorCreate();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
};
