// Fill out your copyright notice in the Description page of Project Settings.


#include "TickableObject.h"

void UTickableObject::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Error, TEXT("UTickableObject::PostInitProperties"));

    //デリゲートを作成
    TickDelegate = FTickerDelegate::CreateUObject(this, &UTickableObject::Tick);
    //登録(ティックの遅延時間も設定可能（今回は設定なし）)
    TickHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);
}

void UTickableObject::BeginDestroy()
{
    Super::BeginDestroy();
    UE_LOG(LogTemp, Error, TEXT("UTickableObject::BeginDestroy"));
   
    //登録解除
    if (TickHandle.IsValid())
    {
        FTicker::GetCoreTicker().RemoveTicker(TickHandle);
        TickHandle.Reset();
    }

}

bool UTickableObject::Tick(float deltaTime)
{
    UE_LOG(LogTemp, Warning, TEXT("UTickableObject::Tick : DeltaTime = %f"), deltaTime);
    return true;
}
