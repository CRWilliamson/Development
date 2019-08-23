// Made by Christopher Williamson

#include "ObjectCommunicationInfo.h"
#include "CodeTest.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractiveObjectInterface.h"

ObjectCommunicationInfo::ObjectCommunicationInfo()
{
}

ObjectCommunicationInfo::~ObjectCommunicationInfo()
{
}

void ObjectCommunicationInfo::SendState(AActor* Target, FString State)
{
	//Get the class of the target object.
	UClass* TargetClass = Target->GetClass();

	//Does the target class implement UInteractiveObjectInterface?
	if (TargetClass->ImplementsInterface(UInteractiveObjectInterface::StaticClass()))
	{
		
		//If so, cast Target to this interface.
		IInteractiveObjectInterface* InterfaceRef = Cast<IInteractiveObjectInterface>(Target);

		//Then call SetState()
		InterfaceRef->SetState(TCHAR_TO_UTF8(*State));
	}
}