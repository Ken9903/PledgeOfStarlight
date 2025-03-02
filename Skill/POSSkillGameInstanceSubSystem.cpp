// Fill out your copyright notice in the Description page of Project Settings.


#include "POSSkillGameInstanceSubSystem.h"

UPOSSkillGameInstanceSubSystem::UPOSSkillGameInstanceSubSystem()
{
	LoadSkillDataTable();
	LoadUtilitySkillDataTable();
}

void UPOSSkillGameInstanceSubSystem::LoadSkillDataTable()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> TargetDataTable(TEXT("/Script/Engine.DataTable'/Game/PledgeOfStarlight/DataTable/DT_SKillDataTable.DT_SKillDataTable'"));
	if(TargetDataTable.Succeeded())
	{
		SkillDataTable = TargetDataTable.Object;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("SkillDataTable Load Failed"));
	}
	return;
}

void UPOSSkillGameInstanceSubSystem::LoadUtilitySkillDataTable()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> TargetDataTable(TEXT("/Script/Engine.DataTable'/Game/PledgeOfStarlight/DataTable/DT_UtilitySkillDataTable.DT_UtilitySkillDataTable'"));
	if(TargetDataTable.Succeeded())
	{
		UtilitySkillDataTable = TargetDataTable.Object;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Utility SkillDataTable Load Failed"));
	}
	return;
}

FSkillData UPOSSkillGameInstanceSubSystem::GetSkillDataFromTable(FName RowName)
{
	if(!SkillDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("SkillDataTable nullptr"));
		return FSkillData();
	}

	FSkillData* SkillData = SkillDataTable->FindRow<FSkillData>(RowName,TEXT(""));

	if (SkillData)
	{
		return *SkillData;
	}

	UE_LOG(LogTemp, Warning, TEXT("SkillDatable can not find %s"), *RowName.ToString());
	return FSkillData();
}

FUtilitySkillData UPOSSkillGameInstanceSubSystem::GetUtilitySkillDataFromTable(FName RowName)
{
	if(!UtilitySkillDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Utility SkillDataTable nullptr"));
		return FUtilitySkillData();
	}

	FUtilitySkillData* UtilitySkillData = UtilitySkillDataTable->FindRow<FUtilitySkillData>(RowName,TEXT(""));

	if (UtilitySkillData)
	{
		return *UtilitySkillData;
	}

	UE_LOG(LogTemp, Warning, TEXT("Utility SkillDatable can not find %s"), *RowName.ToString());
	return FUtilitySkillData();
}

TArray<FSkillMasterInfo> UPOSSkillGameInstanceSubSystem::GetEarnedSkillDataList()
{
	return EarnedSkillDataList;
}

void UPOSSkillGameInstanceSubSystem::AddEarnSkillData(const FSkillMasterInfo SkillData)
{
	EarnedSkillDataList.Add(SkillData);
	return;
}
