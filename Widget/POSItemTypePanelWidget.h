// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ScrollBox.h"
#include "PledgeOfStarlight/Enum/POSItemType.h"
#include "PledgeOfStarlight/Struct/POSItemMasterInfo.h"
#include "POSItemTypePanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API UPOSItemTypePanelWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UScrollBox> ItemListSizeBox;
	
	UPROPERTY(Category = "POS_Widget", EditInstanceOnly, BlueprintReadWrite, meta = (ExposeOnSpawn))
	EItemType ItemPanelType;

	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly)
	int32 MaxHorizontalItemAmount = 7;

	UPROPERTY(Category = "POS_Widget", VisibleDefaultsOnly)
	int32 CurrentHorizontalItemAmount = 0;

	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly)
	TSubclassOf<UUserWidget> WBP_MenuSlot;

	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly)
	TSubclassOf<UUserWidget> WBP_POSItemSingleSlot;
	
	UFUNCTION(Category = "POS_Item", BlueprintCallable)
	void SetUpItemUI();

private:
	UFUNCTION(Category = "POS_Item")
	bool CheckSameItemTypePanel(FItemMasterInfo ItemMasterInfo);

	UPROPERTY(Category = "POS_Widget", VisibleDefaultsOnly)
	TObjectPtr<UUserWidget> MenuSlotLineInstance;
	
	
	
};
