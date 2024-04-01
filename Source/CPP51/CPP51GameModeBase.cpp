// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPP51GameModeBase.h"
#include "Public/MyPawn.h"

ACPP51GameModeBase::ACPP51GameModeBase()
{
	// DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}

void ACPP51GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("My Name is ok"));
	UE_LOG(LogTemp, Error, TEXT("My Name is Error"));
	UE_LOG(LogTemp, Display, TEXT("My Name is Display"));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor(0,90,255), TEXT("My name is print"));


	//创建一个FString,Fstring转化为FName,Fstring转换成Text
	FString MyString = TEXT("I am String");
	FName MyName = FName(*MyString);
	FText MyText = FText::FromString(MyString);

	//FName转成FString
	MyString = MyName.ToString();
	//Fname转化成Ftext
	FText text1 = FText::FromName(MyName);
	//Ftext转化成FString
	FString strFromText = text1.ToString();
	//FTEXT不可以直接转化成FName,需要先转FString,然后转FName

	//PrintF();

	MyMap.Emplace(0, 1); //往Map容器添加 元素(key0,value1)
	MyMap.Emplace(1, 2);
	MyMap.Emplace(2, 3);
	//PrintMap();
	PrintSet();

}

void ACPP51GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP51GameModeBase::PrintF()
{
	MyArray.Add(10);
	MyArray.Add(20);
	MyArray.Add(30);
	MyArray.AddUnique(20);
	MyArray.AddUnique(40);

	//删
	MyArray.Remove(20); //移除数组中所有的等值元素
	MyArray.RemoveAt(0); //移除数组中索引为0的元素
	MyArray.RemoveSingle(10); //移除首个匹配的元素
	MyArray.Empty(); //清空我们的数组
	MyArray.Reset(); //重置所有元素为0.

	//改
	MyArray.Insert(60, 0);//在索引0插入一个元素0
	int32& temp = MyArray[0];
	temp = 50; //修改了数组元素0 为 50

	//查
	MyArray.Contains(10);  //查找数组是否包含了元素10
	MyArray.Find(10); //正向查找第一个匹配得元素，找到了返回真，否则假
	MyArray.FindLast(10); //反向查找，同上
	//迭代器遍历
	for (auto It = MyArray.CreateConstIterator(); It; It++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), *It);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor(255, 44, 32), FString::Printf(TEXT("%d"), *It));
	}
}

void ACPP51GameModeBase::PrintMap()
{
	MyMap.Remove(0); //移除key值为0的元素
	MyMap.Empty(); //清空map容器的数据

	MyMap.Contains(1); //查找key值为1是否存在
	int32* IsFind = MyMap.Find(6); //查找，参数为key值，看key是否存在，返回的是一个指针
	const int32* isFind2 = MyMap.FindKey(2); //反向查找，通过查找value的值来查找key，返回类型是指针
	//分别获取keys和values

	TArray<int32> TestKeys;
	TArray<int32> TestValues;
	MyMap.GenerateKeyArray(TestKeys);
	MyMap.GenerateValueArray(TestValues);

	for (auto& Test:MyMap)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Key:%d" "Value:%d"), Test.Key, Test.Value));
		UE_LOG(LogTemp, Warning, TEXT("Key:%d Value:%d"), Test.Key, Test.Value);
	}
}

void ACPP51GameModeBase::PrintSet()
{
	MySet.Add(TEXT("Banana"));
	MySet.Add(TEXT("GrapeFruit"));
	MySet.Add(TEXT("Pineaplle"));
	MySet.Emplace(TEXT("Orange")); //add和Emplace都是添加到容器中，但是emplacecc可以避免在插入集合时创建的临时文件

	TSet<FString>MySet2;
	MySet2.Add(TEXT("张三"));
	MySet2.Add(TEXT("李四"));
	MySet2.Add(TEXT("王五"));
	
	MySet.Append(MySet2);  //拼接MySet2到MySet
	//删除元素
	MySet.Remove(TEXT("Banana"));//Remove函数会返回已删除元素的数量，如果给定的键未包含在集合中则返回0.
	MySet.Reset(); //清空集合元素但是保留内存
	MySet.Empty(); //清空元素 释放内存
	//查找元素
	int32 Count = MySet.Num(); //num函数查询集合中得元素数量
	bool isFind1 = MySet.Contains(TEXT("Banana"));//查询是否包含特定元素，找到为真否则为假
	FString* isFind2 = MySet.Find(TEXT("Banan")); //Find返回指向元素的指针，如果映射不包含该键，则返回Null
	//Array函数
	TArray<FString> FruitArray = MySet.Array(); //函数会返回一个TArray，其中填充了TSet中每一个元素的副本

	//排序
	TSet<FString> TestSet = { TEXT("a"),TEXT("aa"),TEXT("aaa"),TEXT("aaaa") };
	TestSet.Sort([](FString A, FString B) {return A.Len() > B.Len(); });

	//运算符 = 
	TSet<FString>NewSet;
	NewSet = MySet; //将MySet的里面的值赋给NewSet
	NewSet.Add("TEXT(OneOne)");

	//[]
	FSetElementId Index = NewSet.Add(TEXT("TwoTwo")); //根据FSetElementId访问集合对应元素的引用
	TestSet[Index] = TEXT("One");

	//reserve
	TSet<FString>NewSet1;
	NewSet1.Reserve(10);//预先分配内存，若输入的number大于元素个数，则会产生闲置内存(Slack)

	//Shrink
	for (int32 i = 0; i < 10; i++)
	{
		NewSet1.Add(FString::Printf(TEXT("NewSet%d"), i)); //添加元素
	}
	for (int32 i = 0; i < 10; i += 2) {
		NewSet1.Remove(FSetElementId::FromInteger(i));//删除元素产生闲置内存
	}
	NewSet1.Shrink();//删除末端的空元素

	//Compact将容器中的所有空白的元素集合到一起放到末尾
	NewSet1.Compact(); //注意Compact可能会改变元素间的顺序，若不想改变，可以使用CompactStable
	NewSet1.Shrink();


	for (auto& testset:MySet)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("%s"), *testset));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *testset);
	}
	//基础数据类型打印
	int32 MyInt = 10;
	float MyFloat = 5.0f;
	bool MyBool = true;
	char Mychar = 'A';
	FString MyString1 = TEXT("MYString");
	FVector MyVector = FVector(0, 0, 0);
	UE_LOG(LogTemp, Warning, TEXT("%d"), MyInt);
	UE_LOG(LogTemp, Warning, TEXT("%f"), MyFloat);
	UE_LOG(LogTemp, Warning, TEXT("%d"), MyBool);
	UE_LOG(LogTemp, Warning, TEXT("%c"), Mychar);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *MyString1);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *MyVector.ToString());
}

