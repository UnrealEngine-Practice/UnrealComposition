// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Card.h"
#include "Student.h"
#include "Staff.h"
#include "Teacher.h"

// 클래스 생성자의 값은 CDO에 저장되고 이후에 Init함수에서 SchoolName을 바꿔도
// CDO에 저장된 기본 값은 바뀌지 않는다.
UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	TArray<UPerson*> Persons = { NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>()};

	UE_LOG(LogTemp, Log, TEXT("============================================"));
	for (const auto Person: Persons)
	{
		const UCard* OwnCard = Person->GetCard();
		check(OwnCard);
		ECardType CardType = OwnCard->GetCardType();

		const UEnum* CardEnumType =  FindObject<UEnum>(nullptr, TEXT("/Script/UnrealComposition.ECardType"));
		if (CardEnumType != nullptr)
		{
			FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
			UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드는 %s"), *Person->GetName(), *CardMetaData);
		}
	}
}
