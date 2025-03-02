// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "POSAttackSkillBase.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "POSAttackIceSlash.generated.h"

/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API APOSAttackIceSlash : public APOSAttackSkillBase
{
	GENERATED_BODY()

	APOSAttackIceSlash();

private:
	UPROPERTY(Category = "POS_Collision", VisibleAnywhere)
	TObjectPtr<USphereComponent> AttackCollision;
	
	UPROPERTY(Category = "POS_Effect", VisibleAnywhere)
	TObjectPtr<UNiagaraComponent> IceSlashEffect;

	virtual void BeginPlay() override;
	
	void UseSkill() override;

	UFUNCTION(Category = "POS_Collision")
	void PlayCollision();
	
	UFUNCTION(Category = "POS_Collision")
	void OffCollision();

	UFUNCTION(Category = "POS_Collision")
	void OnAttackCollisionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
