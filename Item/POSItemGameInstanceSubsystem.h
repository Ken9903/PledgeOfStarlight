// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PledgeOfStarlight/Interface/POSItemSubSystemInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PledgeOfStarlight/Struct/POSItemData.h"
#include "PledgeOfStarlight/Struct/POSConsumableItemData.h"
#include "POSItemGameInstanceSubsystem.generated.h"


/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API UPOSItemGameInstanceSubsystem : public UGameInstanceSubsystem, public IPOSItemSubSystemInterface
{
	GENERATED_BODY()

	UPOSItemGameInstanceSubsystem();
	
	UFUNCTION(Category = "POS_Item")
	virtual FItemData GetItemDataFromTable(FName RowName) override;

	UFUNCTION(Category = "POS_Item")
	virtual FConsumableItemData GetConsumableItemDataFromTable(FName RowName) override;

private:
	UPROPERTY(Category = "POS_Item", VisibleAnywhere)
	TObjectPtr<UDataTable> ItemDataTable;

	UPROPERTY(Category = "POS_Item", VisibleAnywhere)
	TObjectPtr<UDataTable> ConsumableItemDataTable;

	UFUNCTION(Category = "POS_Item")
	void LoadItemDataTable();

	UFUNCTION(Category = "POS_Item")
	void LoadConsumableItemDataTable();
	
};
