// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PledgeOfStarlight/Struct/POSNPCInfo.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "POSNPCGameInstanceSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API UPOSNPCGameInstanceSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UPOSNPCGameInstanceSubSystem();

	UFUNCTION(Category = "POS_NPC", BlueprintCallable)
	FPOSNPCInfo GetNPCData(FName NPCID);

private:
	UPROPERTY(Category = "POS_NPC", VisibleDefaultsOnly)
	TObjectPtr<UDataTable> NPCDataTable;

	UFUNCTION(Category = "POS_NPC")
	void LoadNPCDataTable();
	
};
