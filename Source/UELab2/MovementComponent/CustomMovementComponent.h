#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "CustomMovementComponent.generated.h"

UCLASS()
class UELAB2_API UCustomMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*The Pawns Movement Speed */
	UPROPERTY(EditAnywhere, Category = "Movement Properties")
		float Speed = 500;
	
};
