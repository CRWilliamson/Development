// Made by Christopher Williamson
// A class that represents a static mesh that responds to being clicked on.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interfaces/UserInputInterface.h"
#include "Interactive/ObjectCommunicationInfo.h"
#include <map>
#include "ClickableButton.generated.h"

//Inherits from AStaticMeshActor to access the static mesh component and additional features.
//Implements IUseInputInterface to be able to act when input is received by the player pawn.
//Implements ObjectCommunicationInfo so that it can send state information to target objects.

UCLASS()
class CODETEST_API AClickableButton : public AStaticMeshActor, public IUserInputInterface, public ObjectCommunicationInfo
{

	GENERATED_BODY()

public:

	AClickableButton();

	//Called by the player pawn when the left mouse button is pressed, will be used to send corresponding state information.
	virtual void LeftMouseDown() override;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//An array of structs that will contain state information. Can be changed in the editor.
	UPROPERTY(EditAnywhere, Category = "CommunicationInformation")
		TArray<FObjectCommunicationStruct> InstructionsOnClick;
		

	
	
};
