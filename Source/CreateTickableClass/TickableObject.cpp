// Fill out your copyright notice in the Description page of Project Settings.


#include "TickableObject.h"

void UTickableObject::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Error, TEXT("UTickableObject::PostInitProperties"));

    //�f���Q�[�g���쐬
    TickDelegate = FTickerDelegate::CreateUObject(this, &UTickableObject::Tick);
    //�o�^(�e�B�b�N�̒x�����Ԃ��ݒ�\�i����͐ݒ�Ȃ��j)
    TickHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);
}

void UTickableObject::BeginDestroy()
{
    Super::BeginDestroy();
    UE_LOG(LogTemp, Error, TEXT("UTickableObject::BeginDestroy"));
   
    //�o�^����
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
