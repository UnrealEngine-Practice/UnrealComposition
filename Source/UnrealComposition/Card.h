// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

UENUM()
enum class ECardType : uint8
{
	Student = 1 UMETA(DisplayName = "For Student"),
	Teacher UMETA(DisplayName = "For Teacher"),
	Staff UMETA(DisplayName = "For Staff"),
	Invalid
};

/**
 * 
 */
UCLASS()
class UNREALCOMPOSITION_API UCard : public UObject
{
	GENERATED_BODY()
public:
	UCard();
	FORCEINLINE ECardType GetCardType() const {return CardType;}
	FORCEINLINE void SetCardType(ECardType InCardType) {CardType = InCardType;}
private:
	UPROPERTY()
	ECardType CardType;
	// 이번 예제에서는 사용되지 않음.
	UPROPERTY()
	uint32 Id;
};
