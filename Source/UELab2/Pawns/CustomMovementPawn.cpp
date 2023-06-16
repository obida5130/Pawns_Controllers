// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/CustomMovementPawn.h"
#include "CustomMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
ACustomMovementPawn::ACustomMovementPawn()
{
	//TODO: Add the Simple Movement Component to this Pawn
	//CREATE the SimpleMovementComponent
	SimpleMovementComponent = CreateDefaultSubobject<UCustomMovementComponent>(TEXT("SimpleMovementComponent"));

	//ASSIGN the RootComponent to the SimpleMovementComponent->UpdatedComponent variable
	RootComponent = SimpleMovementComponent->UpdatedComponent;

}

void ACustomMovementPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACustomMovementPawn::MoveForward(float Amount)
{
	if (!Controller)
		return;

	//TODO: Implement the Move Forward Logic, what is being passed in and how is this pawns movement logic different from its super class?
	/*
	* Here we bound Rotation with our Controller rotation
	*/
	//Get The Rotation from the Controller and ASSIGN it to a FRotator called Rotation, Controller has a function that returns the Controllers rotation
	FRotator Rotation = Controller->GetControlRotation();


	/*
	* Here we declare we are only changing Yaw rotation, other ones are stable as 0.0f
	*/
	//DECLARE a FRotator called YawRotation and Initialize its pitch=0, roll=0 and the yaw=the controller rotation's yaw
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	
	/*
	* EAxis::X -> is making us move at the direction X!
	*/
	//DECLARE a FVector Direction and assign it to FRotationMatrix(??).GetUnitAxis(??);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);


	/*
	* Apply the forward and back movement
	*/
	//IF the SimpleMovementComponent is not null
	if (SimpleMovementComponent)
		//Add Direction * Amount to the SimpleMovementComponent's Input Vector (There is a function that does this)
		SimpleMovementComponent->AddInputVector(Direction * Amount);

	//ENDIF
}

void ACustomMovementPawn::MoveRight(float Amount)
{
	if (!Controller)
		return;

	//TODO: Implement the Move Right Logic, what is being passed in and how is this pawns movement logic different from its super class. Why isn't there a Tick() function in this Pawn?
	/*
	* Here we bound Rotation with our Controller rotation
	*/
	//Get The Rotation from the Controller and ASSIGN it to a FRotator called Rotation, Controller has a function that returns the Controllers rotation
	FRotator Rotation = Controller->GetControlRotation();


	/*
	* Here we declared we are only changing Yaw rotation, other ones are stable as 0.0f
	*/
	//DECLARE a FRotator called YawRotation and Initialize its pitch=0, roll=0 and the yaw=the controller rotation's yaw
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);


	/*
	* EAxis::Y -> is making us move at the direction Y!
	*/
	//DECLARE a FVector Direction and assign it to FRotationMatrix(??).GetUnitAxis(??);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);



	/*
	* Apply the right and left movement
	*/
	//IF the SimpleMovementComponent is not null
	if (SimpleMovementComponent)
	{
		//Add Direction * Amount to the SimpleMovementComponent's Input Vector (There is a function that does this)
		SimpleMovementComponent->AddInputVector(Direction * Amount);
		//ENDIF
	}
}


