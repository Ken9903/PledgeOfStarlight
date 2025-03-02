// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PledgeOfStarlight/Enum/POSItemID.h"
#include "PledgeOfStarlight/Struct/POSItemData.h"
#include "POSItemBase.generated.h"

UCLASS()
class PLEDGEOFSTARLIGHT_API APOSItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APOSItemBase();
	
	UFUNCTION(Category = "POS_Item")
	virtual void UseItem();

protected:
	UPROPERTY(Category = "POS_Item", EditDefaultsOnly)
	EItemID ItemID;

	UPROPERTY(Category = "POS_Item", VisibleAnywhere)
	FItemData ItemData;

	virtual void BeginPlay() override;
	
};
