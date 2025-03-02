// Fill out your copyright notice in the Description page of Project Settings.


#include "POSIceOrb.h"

#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"

APOSIceOrb::APOSIceOrb()
{
	IceOrbNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("IceOrbNiagaraComponent"));
	RootComponent = IceOrbNiagaraComponent;

	AttackCollision = CreateDefaultSubobject<USphereComponent>(TEXT("AttackCollision"));
	AttackCollision->SetupAttachment(IceOrbNiagaraComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));		
}

void APOSIceOrb::BeginPlay()
{
	GetWorldTimerManager().SetTimer(TimerHandle, this, &APOSIceOrb::StartChasing, ChasingDelay, false);
}

void APOSIceOrb::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}
	
	Super::EndPlay(EndPlayReason);
}

void APOSIceOrb::StartChasing()
{
	ProjectileMovementComponent->Velocity = FVector3d(0, 0, 0);
	ProjectileMovementComponent->bIsHomingProjectile = true;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &APOSIceOrb::DestroyIceOrbActor, LifeTime, false);
}

void APOSIceOrb::DestroyIceOrbActor()
{
	Destroy();
}

void APOSIceOrb::OnAttackCollisionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	HitEvent(OtherActor, SkillData.Damage, 0, GetActorLocation());
	AttackCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetWorldTimerManager().SetTimerForNextTick(this, &APOSIceOrb::DestroyIceOrbActor);
	return;
}
