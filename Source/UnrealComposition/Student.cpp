// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"

UStudent::UStudent()
{
	Name = TEXT("이학생");
}

void UStudent::DoLesson()
{
	UE_LOG(LogTemp, Log, TEXT("%s학생이 공부를 시작했습니다."), *this->GetName());
}
