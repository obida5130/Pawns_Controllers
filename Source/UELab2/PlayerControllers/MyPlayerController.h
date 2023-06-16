// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UELAB2_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
protected:
	/*Called to bind functionality to input*/
	virtual void SetupInputComponent() override;

	/*Called to when the game starts*/
	virtual void BeginPlay() override;

private:
	/*Array of Pawns In the level*/
	UPROPERTY()
	TArray<AActor*> Pawns;

	/*The CurrentPawns Index*/
	int32 CurrentPawnIndex = 0;

	/*The Callback function for the ChangePawn Input Action Event*/
	void ChangePawn();
};
