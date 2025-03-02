// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PledgeOfStarlight/Struct/POSSkillMasterInfo.h"
#include "Components/ScrollBox.h"
#include "POSMainSkillPanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLEDGEOFSTARLIGHT_API UPOSMainSkillPanelWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UScrollBox> SkillListSizeBox;

	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly)
	int32 MaxHorizontalSkillAmount = 3;

	UPROPERTY(Category = "POS_Widget", VisibleDefaultsOnly)
	int32 CurrentHorizontalSkillAmount = 0;

	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly)
	TSubclassOf<UUserWidget> WBP_MenuSlot;

	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly)
	TSubclassOf<UUserWidget> WBP_POSSkillSingleSlot;

	UFUNCTION(Category = "POS_Skill", BlueprintCallable)
	void SetUpSkillUI();

	UFUNCTION(Category = "POS_Widget", BlueprintImplementableEvent , BlueprintCallable)
	void SetInfoSKillSlotButtonDown(FSkillMasterInfo SkillData);

private:
	UPROPERTY(Category = "POS_Widget", VisibleDefaultsOnly)
	TObjectPtr<UUserWidget> MenuSlotLineInstance;
};
