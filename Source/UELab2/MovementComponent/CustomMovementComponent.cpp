#include "CustomMovementComponent.h"

void UCustomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//If there is no pawn owner, The Updated Component is null or we should skip update
    // Make sure that everything is still valid, and that we are allowed to move.
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }

    // Get (and then clear) the movement vector that we set in APawn::Tick
    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime /** 150.0f*/;
    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame * Speed, UpdatedComponent->GetComponentRotation(), true, Hit); //Update the pawns Movement https://docs.unrealengine.com/en-US/API/Runtime/Engine/GameFramework/UMovementComponent/SafeMoveUpdatedComponent/1/index.html
    }
}