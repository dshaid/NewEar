// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UENUM(BlueprintType)
namespace MyEnumType
{
	enum MyCustomEnum
	{
		Type1,
		Type2,
		Type3
	};
}

USTRUCT(BlueprintType)
struct FMyTestSrtuct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,CateGory = "MyTestStruct")
	int32 Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, CateGory = "MyTestStruct")
	FString MyName;
	
};

UCLASS()
class CPP51_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable,Category="MyFunction")
	void PrintF1();
	//���麯���Ķ���BlueprintPure
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="MyFunction")
	bool PrintF2();
	//BlueprintImplementablevent��C++�����������ܶ�����ͼ������
	UFUNCTION(BlueprintImplementableEvent)
	void Test1();
	UFUNCTION(BlueprintImplementableEvent)
	int Test2();
	UFUNCTION(BlueprintImplementableEvent)
	void Test11(const FString &MyString);
	UFUNCTION(BlueprintImplementableEvent)
	int Test22(const FString& MyString);

	//BlueprintNativeEvent��C++��������ʵ�֣���ͼ�����ؿɲ�����
	UFUNCTION(BlueprintNativeEvent)
	void TestA();
	UFUNCTION(BlueprintNativeEvent)
	int TestB();
	UFUNCTION(BlueprintNativeEvent)
	void TestC(const FString &mystring);
	UFUNCTION(BlueprintNativeEvent)
	int TestD(const FString& mystring);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MyEnum")
	TEnumAsByte<MyEnumType::MyCustomEnum> MyCustomEnum;
};
