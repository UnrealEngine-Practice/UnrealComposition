// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"

UTeacher::UTeacher()
{
	Name = TEXT("이선생");
}

void UTeacher::DoLesson()
{
	UE_LOG(LogTemp, Log, TEXT("%s선생님이 수업을 시작했습니다."), *this->GetName());
}
