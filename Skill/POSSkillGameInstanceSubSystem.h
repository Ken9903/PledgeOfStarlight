// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PledgeOfStarlight/Interface/POSSkillSubSystemInterface.h"
#include "PledgeOfStarlight/Struct/POSSkillData.h"
#include "PledgeOfStarlight/Struct/POSSkillMasterInfo.h"
#include "PledgeOfStarlight/Struct/POSUtilitySkillData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "POSSkillGameInstanceSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API UPOSSkillGameInstanceSubSystem : public UGameInstanceSubsystem, public IPOSSkillSubSystemInterface
{
	GENERATED_BODY()
public:
	UPOSSkillGameInstanceSubSystem();

	UFUNCTION(Category = "POS_Skill")
	virtual FSkillData GetSkillDataFromTable(FName RowName) override;
	
	UFUNCTION(Category = "POS_Skill")
	virtual FUtilitySkillData GetUtilitySkillDataFromTable(FName RowName) override;

	UFUNCTION(Category = "POS_Skill")
	virtual TArray<FSkillMasterInfo> GetEarnedSkillDataList() override;

	UFUNCTION(Category = "POS_Skill", BlueprintCallable)
	void AddEarnSkillData(FSkillMasterInfo SkillData);

private:
	UPROPERTY(Category = "POS_Skill", VisibleAnywhere)
	TArray<FSkillMasterInfo> EarnedSkillDataList;
	
	UPROPERTY(Category = "POS_Skill", VisibleAnywhere)
	TObjectPtr<UDataTable> SkillDataTable;

	UPROPERTY(Category = "POS_Skill", VisibleAnywhere)
	TObjectPtr<UDataTable> UtilitySkillDataTable;

	UFUNCTION(Category = "POS_Skill")
	void LoadSkillDataTable();

	UFUNCTION(Category = "POS_Skill")
	void LoadUtilitySkillDataTable();
	
};
