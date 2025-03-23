// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "POSAttackSkillBase.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "POSIceOrb.generated.h"

/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API APOSIceOrb : public APOSAttackSkillBase
{
	GENERATED_BODY()
	
public:
	APOSIceOrb();

	UPROPERTY(Category = "POS_Physics", VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

private:
	UPROPERTY(Category = "POS_Effect", VisibleAnywhere)
	TObjectPtr<UNiagaraComponent> IceOrbNiagaraComponent;

	UPROPERTY(Category = "POS_Collision", VisibleAnywhere)
	TObjectPtr<USphereComponent> AttackCollision;

	UPROPERTY(Category = "POS_Physics", EditDefaultsOnly)
	float HomingAccelerationMagnitude = 3000;

	UPROPERTY(Category = "POS_Physics", VisibleAnywhere)
	FVector HomingVelocity = FVector(1, 400, 400);

	FTimerHandle StartTimerHandle;
	FTimerHandle DestroyTimerHandle;

	UPROPERTY(Category = "POS_Parameter", EditAnywhere)
	float ChasingDelay = 0.1f;
	
	UPROPERTY(Category = "POS_Parameter", EditAnywhere)
	float LifeTime = 2.0f;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(Category = "POS_Skill")
	void StartChasing();

	UFUNCTION(Category = "POS_Skill")
	void DestroyIceOrbActor();

	UFUNCTION(Category = "POS_Collision")
	void OnAttackCollisionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
