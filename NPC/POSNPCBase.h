// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DialogueBuilderObject.h"
#include "Components/SphereComponent.h"
#include "PledgeOfStarlight/Interface/POSGimmickInteractInterface.h"
#include "PledgeOfStarlight/Struct/POSNPCInfo.h"
#include "PledgeOfStarlight/Widget/POSNPCDialogueHighlightWidget.h"
#include "POSNPCBase.generated.h"


UCLASS()
class PLEDGEOFSTARLIGHT_API APOSNPCBase : public ACharacter, public IPOSGimmickInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APOSNPCBase();
	
	UFUNCTION(Category = "POS_Gimmcik", BlueprintCallable)
	virtual void InteractSkill(FName SkillID) override;

protected:
	UPROPERTY(Category = "POS_Collision", EditDefaultsOnly)
	TObjectPtr<USphereComponent> DialogueTrigger;

	UPROPERTY(Category = "POS_NPC", EditDefaultsOnly)
	TObjectPtr<UDialogueBuilderObject> DialogueBuilderObject;

	UPROPERTY(Category = "POS_NPC", EditDefaultsOnly, BlueprintReadOnly)
	FName NPCID;

	UPROPERTY(Category = "POS_NPC", VisibleAnywhere, BlueprintReadOnly)
	FPOSNPCInfo NPCInfo;

	UPROPERTY(Category = "POS_Gimmick", VisibleAnywhere, BlueprintReadOnly) //TODO : Save
	TMap<FName, bool> GimmickSuccessMap;

	//대화클릭시 true로 변경.
	UPROPERTY(Category = "POS_Gimmick", VisibleAnywhere, BlueprintReadOnly)//TODO : Save
	TMap<FName, bool> GimmickExecutionMap;

	//Gimmick Data Save Check
	UPROPERTY(Category = "POS_Gimmick", VisibleAnywhere, BlueprintReadOnly)//TODO : Save
	uint8 isSaved : 1 = false; 
	
	UPROPERTY(Category = "POS_Widget", EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UPOSNPCDialogueHighlightWidget> NPCDialogueHighlightWidget;

	UPROPERTY(Category = "POS_Widget", VisibleDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UPOSNPCDialogueHighlightWidget> NPCDialogueHighlightWidgetInstance;
	
	virtual void BeginPlay() override;

	void InitGimmickMap(); // 저장된 데이터가 없을 경우 실행.

	UFUNCTION(Category = "POS_Collision")
	void OnDialogueCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION(Category = "POS_Collision")
	void OnDialogueCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	

};