// Made by Christopher Williamson
// This class will be used by any object expecting to be interacted with. This contains the state information as well as the function that will be called whenever the state is set.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include <string>
#include "InteractiveObjectInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractiveObjectInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CODETEST_API IInteractiveObjectInterface
{
	GENERATED_BODY()

	private:

		//A string representing an object's current state.
		std::string state;

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

		//Called whenever something wants to set the state.
		virtual void SetState(std::string StateToSet);
		
};
