// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/SimplePawn.h"
#include "CustomMovementPawn.generated.h"

/**
 * 
 */
UCLASS()
class UELAB2_API ACustomMovementPawn : public ASimplePawn
{
	GENERATED_BODY()

public:
	ACustomMovementPawn();

	/*The pawns SimpleMovementComponent. This Pawn will use a custom movement component*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
		class UCustomMovementComponent* SimpleMovementComponent;

	/*Called to bind functionality to input*/
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*The Callback function for the MoveForward Input Axis Event*/
	virtual void MoveForward(float Amount) override;
	/*The Callback function for the MoveRight Input Axis Event*/
	virtual void MoveRight(float Amount) override;
};
