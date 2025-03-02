// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PledgeOfStarlight/PledgeOfStarlightCharacter.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "POSSaveLoadGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API UPOSSaveLoadGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(Category = "POS_Save")
	void SaveEarnedSkillList();
	
	UFUNCTION(Category = "POS_Save")
	void LoadEarnedSkillList();
	
	UFUNCTION(Category = "POS_Save")
	void SavePresetList();
	
	UFUNCTION(Category = "POS_Save")
	void LoadPresetList();
	
	UFUNCTION(Category = "POS_Save")
	void SaveInventory();
	
	UFUNCTION(Category = "POS_Save")
	void LoadInventory();

	void CheckPlayer();

	void InitPlayer();

private:
	FString EarnedSkillListSlotName = TEXT("EarnedSkillSlot");
	FString PresetSkillListSlotName = TEXT("PresetSlot");
	FString InventorySlotName = TEXT("InventorySlot");

	UPROPERTY(Category = "POS_Save", VisibleAnywhere)
	TObjectPtr<APledgeOfStarlightCharacter> POSPlayer;
};
