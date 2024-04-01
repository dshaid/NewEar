// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Public/MyPlayerController.h"
#include "Public/MyHUD.h"
#include "Public/MyPlayerState.h"
#include "CPP51GameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class CPP51_API ACPP51GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	ACPP51GameModeBase();
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime)override;


	bool varBool;
	int32 varInt32;
	int64 varInt64;
	BYTE varByte;
	FString varString;
	FName varName;
	FText varText;
	FVector varVector; 
	FRotator varRotator;
	FTransform varTransform;

	TArray<int32>MyArray;

	void PrintF();

	TMap<int32, int32>MyMap;

	void PrintMap();

	TSet<FString>MySet;

	void PrintSet();
};
