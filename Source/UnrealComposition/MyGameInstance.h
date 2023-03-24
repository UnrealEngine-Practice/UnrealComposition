// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCOMPOSITION_API UMyGameInstance final : public UGameInstance
{
	GENERATED_BODY()
public :
	UMyGameInstance();

	virtual void Init() override;

private:
	// SchoolName이라는 property는 기본값을 지정하지 않으면 그냥 빈 문자열이다.
	// 생성자 코드에 기본 값을 지정할 수 있다.
	UPROPERTY()
	FString SchoolName; 
};
