// Fill out your copyright notice in the Description page of Project Settings.


#include "Person.h"
#include "Card.h"

UPerson::UPerson()
{
	Name = TEXT("홍길동");

	// 생성자에서는 CreateDefaultSubobject를 사용해야한다.
	// FSTring이 아닌 FName에 대해서 NAME_을 명시적으로 써줄 수 있다.
	Card = CreateDefaultSubobject<UCard>(TEXT("NAME_Card"));
}
