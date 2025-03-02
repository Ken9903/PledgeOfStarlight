// Fill out your copyright notice in the Description page of Project Settings.


#include "POSEnemyBase.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APOSEnemyBase::APOSEnemyBase()
{
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;
	
	HitPoint = CreateDefaultSubobject<USceneComponent>(TEXT("HitPoint"));
	HitPoint->SetupAttachment(SkeletalMesh);
	
	DialogueTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("DialogueTrigger"));
	DialogueTrigger->SetupAttachment(SkeletalMesh);
	DialogueTrigger->SetSphereRadius(150.0f);

}

void APOSEnemyBase::TakeDamage(float Damage, float SoundDelay)
{
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(
	TimerHandle, // 타이머 핸들
	this,        // 실행할 객체
	&APOSEnemyBase::PlayHitSound, // 실행할 함수
	SoundDelay,        // 실행까지 걸리는 시간 (초)
	false        // 반복 여부 (false면 1회 실행, true면 반복 실행)
);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Take Damage : %.2f"), Damage));
	}
	return;
}

void APOSEnemyBase::PlayHitSound()
{
	if (HitSound)
	{
		UGameplayStatics::PlaySound2D(this, HitSound);
	}
}




