// Fill out your copyright notice in the Description page of Project Settings.


#include "POSAttackIceHorming.h"

#include "AudioDevice.h"
#include "Kismet/GameplayStatics.h"

APOSAttackIceHorming::APOSAttackIceHorming()
{
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	RootComponent = RootSceneComponent;
	
	HitSearchArea = CreateDefaultSubobject<USphereComponent>(TEXT("HitSearchArea"));
	HitSearchArea->SetupAttachment(RootSceneComponent);
	HitSearchArea->SetSphereRadius(32.0f);

	SkillID = ESkillID::Temp3;
	AttachPosition = FVector3d(0, 0, 160);
}

void APOSAttackIceHorming::BeginPlay()
{
	Super::BeginPlay();
	HitSearchArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	InitTransform();
	return;
}

void APOSAttackIceHorming::UseSkill()
{
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(GetActorLocation());
	SpawnTransform.SetRotation(GetActorRotation().Quaternion());
	SpawnTransform.SetScale3D(FVector(1.0f, 1.0f, 1.0f));
	POSIceOrb = GetWorld()->SpawnActor<APOSIceOrb>(POSIceOrbClass, SpawnTransform);

	UGameplayStatics::PlaySound2D(this, UsingSound);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Use Ice Orb"));
	}
	StartCollisionTrigger();
	return;
}

void APOSAttackIceHorming::StartCollisionTrigger()
{
	HitSearchArea->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &APOSAttackIceHorming::EndCollisionTrigger, CollisionDuration, false);
	return;
}

void APOSAttackIceHorming::EndCollisionTrigger()
{
	HitSearchArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	return;
}
