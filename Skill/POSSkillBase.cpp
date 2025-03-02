// Fill out your copyright notice in the Description page of Project Settings.


#include "POSSkillBase.h"

#include "POSSkillGameInstanceSubSystem.h"

APOSSkillBase::APOSSkillBase()
{
	static ConstructorHelpers::FObjectFinder<USoundWave> SoundAsset(TEXT("/Script/Engine.SoundWave'/Game/Free_Sounds_Pack/Cash_Register_1-2.Cash_Register_1-2'"));
	if (SoundAsset.Succeeded())
	{
		UsingSound = SoundAsset.Object;
	}
}

void APOSSkillBase::BeginPlay()
{
	Super::BeginPlay();
	UPOSSkillGameInstanceSubSystem* SkillSubSystem = GetGameInstance()->GetSubsystem<UPOSSkillGameInstanceSubSystem>();
	if(SkillSubSystem)
	{
		IPOSSkillSubSystemInterface* SkillSubSystemInterface = Cast<IPOSSkillSubSystemInterface>(SkillSubSystem);
		if(SkillSubSystemInterface)
		{
			FString EnumName = UEnum::GetValueAsString(SkillID);
			SkillData = SkillSubSystemInterface->GetSkillDataFromTable(FName(EnumName.Replace(TEXT("ESkillID::"), TEXT(""))));
		}
	}
	return;
}

void APOSSkillBase::UseSkill()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Use Default SKill"));
	}
	return;
}

void APOSSkillBase::InitTransform()
{
	SetActorRelativeLocation(AttachPosition);
	SetActorRelativeRotation(AttachRotation);
	return;
}
