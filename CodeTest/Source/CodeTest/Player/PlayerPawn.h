// Made by Christopher Williamson
// This class represents the player pawn, which points in a certain direction and handles user inputs.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "PlayerPawn.generated.h"

UCLASS()
class CODETEST_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Get whatever the mouse is currently hovering over so that the pawn knows what to communicate with during interactions.
	void GetMouseOverObject();

	//Create the camera and mesh components for the pawn.
	UPROPERTY(EditAnywhere)
	UCameraComponent* OurCamera;
	UStaticMeshComponent* OurVisibleComponent;

};
