// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "PledgeOfStarlight/Interface/POSEnemyInterface.h"
#include "POSEnemyBase.generated.h"

UCLASS()
class PLEDGEOFSTARLIGHT_API APOSEnemyBase : public AActor, public IPOSEnemyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APOSEnemyBase();

	virtual void TakeDamage(float Damage, float SoundDelay) override;

private:
	UPROPERTY(Category = "POS_Enemy", VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh;
	
	UPROPERTY(Category = "POS_Hit", VisibleAnywhere)
	TObjectPtr<USceneComponent> HitPoint;

	UPROPERTY(Category = "POS_Collision", VisibleAnywhere)
	TObjectPtr<USphereComponent> DialogueTrigger;
	
	UPROPERTY(Category = "POS_Sound", EditAnywhere)
	TObjectPtr<USoundBase> HitSound;

	UFUNCTION(Category = "POS_Sound")
	void PlayHitSound();

};
