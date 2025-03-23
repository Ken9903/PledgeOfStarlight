// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "POSQuestSingleSlot.h"
#include "Blueprint/UserWidget.h"
#include "Components/ScrollBox.h"
#include "PledgeOfStarlight/Enum/POSQuestProgressType.h"
#include "POSQuestTypePanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API UPOSQuestTypePanelWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(Category = "POS_Widget", BlueprintReadWrite)
	TObjectPtr<UPOSQuestMainPanelWidget> QuestMainPanelWidget;
	
	UFUNCTION(Category = "POS_Item", BlueprintCallable)
	void SetUpQuestUI();

protected:
	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UScrollBox> QuestScrollBox;
	
	UPROPERTY(Category = "POS_Widget", EditInstanceOnly, BlueprintReadWrite, meta = (ExposeOnSpawn))
	EPOSQuestProgressType QuestPanelType;

	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly)
	TSubclassOf<UPOSQuestSingleSlot> WBP_POSQuestSingleSlotClass;

	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly)
	TObjectPtr<UPOSQuestSingleSlot> QuestSingleSlotInstance;
	
};
