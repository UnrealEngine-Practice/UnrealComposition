// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
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
	UE_LOG(LogTemp, Log, TEXT("학교 이름 % s"), *this->SchoolName);
	for (const auto Person : Persons)
	{
		UE_LOG(LogTemp, Log, TEXT("구성원 이름 %s"), *Person->GetName());
	}
	UE_LOG(LogTemp, Log, TEXT("============================================"));

	for (auto Person : Persons)
	{
		ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
		if (LessonInterface == nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 없습니다."), *Person->GetName());
		}
		else
		{
			LessonInterface->DoLesson();
		}
	}
}
