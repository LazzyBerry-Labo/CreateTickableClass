// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Ticker.h"
#include "TickableObject.generated.h"


/**
 * Tick���o�^���ꂽObject
 * �Q�[���X���b�h�Ń}�C�t���[���A���O���o�͂���
 */
UCLASS(BlueprintType, Blueprintable)
class CREATETICKABLECLASS_API UTickableObject : public UObject
{
	GENERATED_BODY()
	
public:
	//Called after Begining PlayGame
	//Tick�̃f���Q�[�g��o�^����
	virtual void BeginPlay() override;

	//Called before destroying the object.
	//Tick�̃f���Q�[�g��o�^��������
	virtual void BeginDestroy() override;

	//�Q�[���X���b�h�Ń}�C�t���[�����������
    //DeltaSecond �C���^�[�o������
	//bool ����
	bool Tick(float deltaTime);
	
private:
	//Tick�̃f���Q�[�g
	FTickerDelegate TickDelegate;

	//Tick�̃f���Q�[�g�n���h��
	FDelegateHandle TickHandle;
};
