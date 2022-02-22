// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Ticker.h"
#include "TickableObject.generated.h"


/**
 * Tickが登録されたObject
 * ゲームスレッドでマイフレーム、ログを出力する
 */
UCLASS(BlueprintType, Blueprintable)
class CREATETICKABLECLASS_API UTickableObject : public UObject
{
	GENERATED_BODY()
	
public:
	//Called after Begining PlayGame
	//Tickのデリゲートを登録する
	virtual void BeginPlay() override;

	//Called before destroying the object.
	//Tickのデリゲートを登録解除する
	virtual void BeginDestroy() override;

	//ゲームスレッドでマイフレーム処理される
    //DeltaSecond インターバル時間
	//bool 成否
	bool Tick(float deltaTime);
	
private:
	//Tickのデリゲート
	FTickerDelegate TickDelegate;

	//Tickのデリゲートハンドル
	FDelegateHandle TickHandle;
};
