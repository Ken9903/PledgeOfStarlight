// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "POSUtilitySkillData.generated.h"

USTRUCT(BlueprintType)
struct FUtilitySkillData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = "POS_Skill", EditAnywhere)
	float HPHealAmount;

	UPROPERTY(Category = "POS_Skill", EditAnywhere)
	float MPHealAmount;
	
	UPROPERTY(Category = "POS_Skill", EditAnywhere)
	float SpeedPlusAmount;

	UPROPERTY(Category = "POS_Skill", EditAnywhere)
	float AttackPlusAmount;

	UPROPERTY(Category = "POS_Skill", EditAnywhere)
	float DefendPlusAmount;
	
};