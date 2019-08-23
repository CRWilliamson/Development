// Made by Christopher Williamson
// A class that will act as an interface with input functions that can be called on objects implementing this class.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UserInputInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUserInputInterface : public UInterface
{
	GENERATED_BODY()
};

class CODETEST_API IUserInputInterface
{
	GENERATED_BODY()

public:

	//Called by the player pawn when the left mouse button is pressed.
	virtual void LeftMouseDown();

};
