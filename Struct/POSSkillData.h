// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PledgeOfStarlight/Enum/POSSkillID.h"
#include "PledgeOfStarlight/Enum/POSSkillType.h"
#include "POSSkillData.generated.h"

USTRUCT(BlueprintType)
struct FSkillData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	FName Name;
	
	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class APOSSkillBase> SkillClass;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	ESkillID SkillID;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	ESkillType SkillType;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite, meta = (MultiLine = "true"))
	FText Description;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	UTexture2D* IconImage;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	int32 MP;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	int32 Unique;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	float CoolTime;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(Category = "POS_Skill", EditAnywhere, BlueprintReadWrite)
	UDataTable* DataTable;
};

