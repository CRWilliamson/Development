// Made by Christopher Williamson
// A class that can be used to communicate with target objects by find them and sending them states.

#pragma once

#include "CoreMinimal.h"
#include "ObjectCommunicationInfo.generated.h"

//Create a struct that will contain the information needed to communicate with other objects effectively. This will be accessible in the editor.
USTRUCT(BlueprintType)
struct FObjectCommunicationStruct
{
	GENERATED_BODY()

	//Target of a particular state change.
	UPROPERTY(EditAnywhere)
	AActor* Target;

	//The state to change to.
	UPROPERTY(EditAnywhere)
	FString StateToSet;

	FObjectCommunicationStruct()
	{
		
	
	}
	

};

class CODETEST_API ObjectCommunicationInfo
{
public:

	//Send a state change to a target object. If the object does not implement the appropriate interface, silently fail.
	void SendState(AActor* Target, FString State);

	ObjectCommunicationInfo();
	~ObjectCommunicationInfo();
};
