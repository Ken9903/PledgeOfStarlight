// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "POSSkillBase.h"
#include "NiagaraFunctionLibrary.h"
#include "POSAttackSkillBase.generated.h"

UCLASS()
class PLEDGEOFSTARLIGHT_API APOSAttackSkillBase : public APOSSkillBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Category = "POS_Hit", EditDefaultsOnly)
	UNiagaraSystem* HitFlash;

	UPROPERTY(Category = "POS_Hit", EditDefaultsOnly)
	float HitPreDelay = 0.0f;

	UPROPERTY(Category = "POS_Collision", EditDefaultsOnly)
	float CollisionDuration = 0.2f;

	UFUNCTION(Category = "POS_Hit")
	void HitEvent(AActor* HitActor, float Damage, float Delay, FVector HitLocation);

	UFUNCTION(Category = "POS_Hit")
	void AppearHitFlash(FVector HitLocation);
	
};
