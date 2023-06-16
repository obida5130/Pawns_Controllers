// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SimplePawn.generated.h"


class UCameraComponent;
class USpringArmComponent;

UCLASS()
class UELAB2_API ASimplePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASimplePawn();

	/*The Pawns SceneComponent. This will be set as the Root Component*/
	UPROPERTY(EditAnywhere, Category="My Pawn")
		USceneComponent* SceneComponent;

	/*The Pawns SceneComponent. This will be set as the Root Component*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
		USceneComponent* MeshSceneComponent;

	/*The pawns StaticMeshComponent, this will the Pawns visual*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
		UStaticMeshComponent* StaticMeshComponent;

	/*The pawns SpringArmComponent, this is the camera boom and will be attached to the RootComponent*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
		USpringArmComponent* SpringArmComponent;

	/*The pawns CameraComponent, this will be attached to the SpringArmComponent*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
		UCameraComponent* CameraComponent;

	/*The pawns velocity modifier*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
		float Velocity = 300.0f;

	//Possess virtual function
	/*Called when this pawn is posessed by a Player Controller*/
	virtual void PossessedBy(AController* NewController) override;
	/*Called when this pawn is un-posessed by a Player Controller*/
	virtual void UnPossessed() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*Called to bind functionality to input*/
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	/*The Pawns Move Forward Amount per frame*/
	float MoveForwardAmount = 0;
	/*The Pawns Move Right Amount per frame*/
	float MoveRightAmount = 0;

	/*The Callback function for the MoveForward Input Axis Event*/
	virtual void MoveForward(float Amount);
	/*The Callback function for the MoveRight Input Axis Event*/
	virtual void MoveRight(float Amount);


};
