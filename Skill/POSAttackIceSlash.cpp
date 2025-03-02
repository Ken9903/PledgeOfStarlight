// Fill out your copyright notice in the Description page of Project Settings.


#include "POSAttackIceSlash.h"
#include "Kismet/GameplayStatics.h"

APOSAttackIceSlash::APOSAttackIceSlash()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	
	AttackCollision = CreateDefaultSubobject<USphereComponent>(TEXT("AttackCollision"));
	AttackCollision->SetupAttachment(RootComponent);
	AttackCollision->SetSphereRadius(200.0f);
	
	IceSlashEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_POSIceSlash"));
	IceSlashEffect->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<USoundWave> SoundAsset(TEXT("/Script/Engine.SoundWave'/Game/PledgeOfStarlight/Sound/Skill/SW_POSIceSlash.SW_POSIceSlash'"));
	if (SoundAsset.Succeeded())
	{
		UsingSound = SoundAsset.Object;
	}

	SkillID = ESkillID::Temp1;
	AttachPosition = FVector(0,0,100);
	
}

void APOSAttackIceSlash::BeginPlay()
{
	Super::BeginPlay();
	AttackCollision->OnComponentBeginOverlap.AddDynamic(this, &APOSAttackIceSlash::OnAttackCollisionOverlap);
	InitTransform();
	return;
}

void APOSAttackIceSlash::UseSkill()
{
	IceSlashEffect->SetActive(true, true);
	UGameplayStatics::PlaySound2D(this, UsingSound);

	PlayCollision();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Use Ice Slash"));
	}
	return;
	
}
void APOSAttackIceSlash::PlayCollision()
{
	AttackCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle, 
		this, 
		&APOSAttackIceSlash::OffCollision,  
		CollisionDuration,                   
		false                   
	);
	return;
}
void APOSAttackIceSlash::OffCollision()
{
	AttackCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	return;
}

void APOSAttackIceSlash::OnAttackCollisionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	HitEvent(OtherActor, SkillData.Damage, 0, OtherActor->GetActorLocation());
	return;
}

