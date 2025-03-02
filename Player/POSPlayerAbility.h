// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PledgeOfStarlight/Skill/POSSkillBase.h"
#include "PledgeOfStarlight/Item/POSItemBase.h"
#include "PledgeOfStarlight/Struct/POSSlotData.h"
#include "PledgeOfStarlight/Widget/POSSlotPresetWidget.h"
#include "POSPlayerAbility.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLEDGEOFSTARLIGHT_API UPOSPlayerAbility : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPOSPlayerAbility();

	UFUNCTION(Category = "POS_Preset")
	void UsePreset(int32 InputNumber);

	UFUNCTION(Category = "POS_Preset", BlueprintCallable)
	void SetSkillPreset(int32 Index, TSubclassOf<APOSSkillBase> SkillClass);
	
	UFUNCTION(Category = "POS_Preset", BlueprintCallable)
	void SetItemPreset(int32 Index, TSubclassOf<APOSItemBase> ItemClass);

	UFUNCTION(Category = "POS_Preset", BlueprintCallable)
	void SetPresetData(int32 Index, FSlotData SlotData);

	UFUNCTION(Category = "POS_Preset")
	bool CheckSkillPresetSlotValid(int32 Number);

	UFUNCTION(Category = "POS_Preset", BlueprintCallable)
	TArray<FSlotData> GetPresetDataList();
	
	UPROPERTY(Category = "POS_Preset", VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UUserWidget> WBP_POSMainWidgetInstance;

	UFUNCTION(Category = "POS_Preset")
	void SetPresetDataList(TArray<FSlotData> InPresetDataList);

	UFUNCTION(Category = "POS_Preset", BlueprintCallable)
	void CreateInGamePresetPanel();

private:
	UPROPERTY(Category = "POS_Preset", EditAnywhere)
	TArray<FSlotData> PresetDataList;

	UPROPERTY(Category = "POS_Preset", VisibleAnywhere)
	TArray<TSubclassOf<APOSSkillBase>> SkillPresetClassList;

	UPROPERTY(Category = "POS_Preset", VisibleAnywhere)
	TArray<TSubclassOf<APOSItemBase>> ItemPresetClassList;

	UPROPERTY(Category = "POS_Preset", VisibleAnywhere)
	TArray<APOSSkillBase*> SkillSpawnPool;

	UPROPERTY(Category = "POS_Preset", VisibleAnywhere)
	TArray<APOSItemBase*> ItemSpawnPool;

	UPROPERTY(Category = "POS_Preset", EditDefaultsOnly)
	TSubclassOf<UUserWidget> WBP_POSMainWidget;

	/*UPROPERTY(Category = "POS_Preset", VisibleAnywhere)
	TObjectPtr<class APOSDefaultSkill> DefaultSkill;
	
	UPROPERTY(Category = "POS_Preset", VisibleAnywhere)
	TObjectPtr<class APOSDefaultItem> DefaultItem;*/

	virtual void BeginPlay() override;
	
	UFUNCTION(Category = "POS_Preset")
	void InitSkillPreset();

	UFUNCTION(Category = "POS_Preset", BlueprintCallable)
	void InitSpawnPool();
		
};
