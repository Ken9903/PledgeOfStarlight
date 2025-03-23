// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "POSQuestGameInstanceSubSystem.generated.h"

enum class EPOSQuestProgressType : uint8;
struct FPOSQuestInfo;
/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API UPOSQuestGameInstanceSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UPOSQuestGameInstanceSubSystem();

	//QuestData
	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	FPOSQuestInfo GetQuestData(FName QuestID);
	
	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	EPOSQuestProgressType FindQuestStatus(FName QuestID);

	//QuestDataList
	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	TSet<FName> GetStartAbleList();

	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	TSet<FName> GetCompletedListList();
	
	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	TSet<FName> GetInProgressList();

	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	int32 GetInProgressStatus(FName QuestID);

	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	void AddInProgressStatus(FName QuestID, int32 Amount);

	
	//Append QuestData
	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	void AppendInAccessibleQuest(FName QuestID);

	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	void AppendStartAbleQuest(FName QuestID);

	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	void AppendInProgressQuest(FName QuestID);

	UFUNCTION(Category = "POS_Quest", BlueprintCallable)
	void AppendCompletedQuest(FName QuestID);
	
private:
	UPROPERTY(Category = "POS_Quest", VisibleDefaultsOnly)
	TObjectPtr<UDataTable> QuestDataTable;

	UPROPERTY(Category = "POS_Quest", VisibleDefaultsOnly)
	TSet<FName> InAccessibleList;

	UPROPERTY(Category = "POS_Quest", VisibleDefaultsOnly)
	TSet<FName> StartAbleList;

	UPROPERTY(Category = "POS_Quest", VisibleDefaultsOnly)
	TSet<FName> InProgressList;
	
	UPROPERTY(Category = "POS_Quest", VisibleDefaultsOnly)
	TMap<FName, int32> InProgressStatus; //진행 상태 저장용.

	UPROPERTY(Category = "POS_Quest", VisibleDefaultsOnly)
	TSet<FName> CompletedList;

	UFUNCTION(Category = "POS_Quest")
	void LoadQuestDataTable();

	UFUNCTION(Category = "POS_Quest")
	void InitQuestStatus();
	
	
};
