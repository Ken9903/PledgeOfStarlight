// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/POSPlayerInterface.h"
#include "Logging/LogMacros.h"
#include "Player/POSPlayerAbility.h"
#include "Player/POSPlayerInventory.h"
#include "PledgeOfStarlightCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class APledgeOfStarlightCharacter : public ACharacter, public IPOSPlayerInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = POS_Ability, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPOSPlayerAbility> PlayerAbility;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = POS_Inventory, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPOSPlayerInventory> PlayerInventory;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* MappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TArray<UInputAction*> PresetActionList;

	

public:
	APledgeOfStarlightCharacter();

	UFUNCTION(Category = "POS_Player")
	virtual UPOSPlayerAbility* GetPlayerAbility() override;

	UFUNCTION(Category = "POS_Player")
	virtual UPOSPlayerInventory* GetPlayerInventory() override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void RunPreset0(const FInputActionValue& Value);
	void RunPreset1(const FInputActionValue& Value);
	void RunPreset2(const FInputActionValue& Value);
	void RunPreset3(const FInputActionValue& Value);
	void RunPreset4(const FInputActionValue& Value);
	void RunPreset5(const FInputActionValue& Value);
	void RunPreset6(const FInputActionValue& Value);
	void RunPreset7(const FInputActionValue& Value);
	void RunPreset8(const FInputActionValue& Value);
	void RunPreset9(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
};

