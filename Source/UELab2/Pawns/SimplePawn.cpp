// Fill out your copyright notice in the Description page of Project Settings.


#include "SimplePawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"


DEFINE_LOG_CATEGORY_STATIC(LogSimplePawn, All, All)

// Sets default values
ASimplePawn::ASimplePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//TODO: Create the component hierarchy in for this actor. What does the hierarchy look like. Draw it out on paper
	//CREATE scene component
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	
	//SET the Scene Component as the  Root Component
	RootComponent = SceneComponent;
	//CREATE Static Mesh Component
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	//ATTACH the Static Mesh Component to the Root Component
	StaticMeshComponent->SetupAttachment(RootComponent);
	//CREATE Spring Arm Component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));

	//ATTACH the Spring Arm Component to the Root Component
	SpringArmComponent->SetupAttachment(RootComponent);

	//CREATE Camera Component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	//ATTACH the Spring Arm Component to the Spring Arm Component
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

	//SET the Spring Arm to Use Pawn Control Rotation (bUsePawnControlRotation)
	SpringArmComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ASimplePawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASimplePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//TODO: Implement the movement. Think about how the movement is done after you have written the implementation code. 
	//IF the Controller is NOT null
	if (GetController() != nullptr)
	{
		//DECLARE a FRotator Rotation and Initialize it to pitch=0, roll=0 and the Yaw to the Controllers Yaw Rotation
		FRotator Rotation(0.f, GetController()->GetControlRotation().Yaw, 0.f);
		//DECLARE a FVector Direction and set it to zero vector
		FVector Direction(0.f);
		//IF the MoveForwardAmount is not zero
		if (MoveForwardAmount != 0.f)
		{
			//SET the Direction to this Actors Location + FRotationMatrix(??).GetUnitAxis(??) * MoveForwardAmount * Velocity * DeltaTime
			Direction = GetActorLocation() + FRotationMatrix(Rotation).GetUnitAxis(EAxis::X) * MoveForwardAmount * Velocity * DeltaTime;
			//SET this actors location to the Direction
			SetActorLocation(Direction);
		}
		//ENDIF

		//IF the MoveRightAmount is not zero
		if (MoveRightAmount != 0.f)
		{
			//SET the Direction to this Actors Location + FRotationMatrix(??).GetUnitAxis(??) * MoveForwardAmount * Velocity * DeltaTime
			Direction = GetActorLocation() + FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y) * MoveRightAmount * Velocity * DeltaTime;
			//SET this actors location to the Direction
			SetActorLocation(Direction);
		}
		//ENDIF
		
	}
	//ENDIF
}

// Called to bind functionality to input
void ASimplePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//TODO: Set up the Input Bindings. Be mindful of each input binding. What is the difference between the movement and looking around
	//IF PlayerInputComponent Is Not null
	if (PlayerInputComponent)
	{
		//BIND axis "MoveForward" to this objects MoveForward() Function
		PlayerInputComponent->BindAxis("MoveForward", this, &ASimplePawn::MoveForward);

		//BIND axis "MoveRight" to this objects MoveRight() Function
		PlayerInputComponent->BindAxis("MoveRight", this, &ASimplePawn::MoveRight);

		//BIND axis "LookUp" to this objects APawn's AddControllerPitchInput Function
		PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

		//BIND axis "LookRight" to this objects APawn's AddControllerYawInput Function
		PlayerInputComponent->BindAxis("LookRight", this, &APawn::AddControllerYawInput);

	}
	//ENDIF
}

void ASimplePawn::MoveForward(float Amount)
{
	//TODO: Set the MoveForwardAmount, what are the values passed in
	//ASSIGN Amount to MoveForwardAmount
	MoveForwardAmount = Amount;

}

void ASimplePawn::MoveRight(float Amount)
{
	//TODO: Set the MoveRightAmount, what are the values passed in
	//ASSIGN Amount to MoveRightAmount
	MoveRightAmount = Amount;

}

void ASimplePawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!NewController) 
		return;
	UE_LOG(LogSimplePawn, Warning, TEXT("%s PossessBy: %s"), *GetName(), *NewController->GetName());
}

void ASimplePawn::UnPossessed()
{
	Super::UnPossessed();
	UE_LOG(LogSimplePawn, Warning, TEXT("%s Un Prossessed"), *GetName());
}

