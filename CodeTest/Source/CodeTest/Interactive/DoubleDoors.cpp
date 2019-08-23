// Made by Christopher Williamson

#include "DoubleDoors.h"
#include "StaticLibraries/ActorTranslationLibrary.h"

ADoubleDoors::ADoubleDoors()
{
	//Create the new scene component.
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Create the new static mesh component.
	RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightDoor"));

	//Set the root component to be the new scene component. The two static mesh components are now attached to it.
	RootComponent = SceneComponent;
	
}

ADoubleDoors::~ADoubleDoors()
{
	
	
}


void ADoubleDoors::PopulateDoorInfo()
{
	//Set properties for both of the doors.
	GetDoors()[0].ObjectRef = Cast<UObject>(GetStaticMeshComponent());
	GetDoors()[0].CloseTransform = GetStaticMeshComponent()->GetRelativeTransform();
	GetDoors()[0].OpenTransform = DoorOpenTransform;

	GetDoors()[1].ObjectRef = Cast<UObject>(RightDoor);
	GetDoors()[1].CloseTransform = RightDoor->GetRelativeTransform();
	GetDoors()[1].OpenTransform = SecondDoorOpenTransform;

}

bool ADoubleDoors::IsDoorMotionComplete()
{
	//Return the result of checking if the transform of the doors match their interpolation targets.
	return (GetStaticMeshComponent()->GetRelativeTransform().Equals(GetDoors()[0].InterpTarget, 0.001) && RightDoor->GetRelativeTransform().Equals(GetDoors()[0].InterpTarget, 0.001));
}

DoorInfo* ADoubleDoors::GetDoors()
{
	//Return array Doors.
	return Doors;
}

int ADoubleDoors::GetDoorsLength()
{
	//Return int DoorsLength.
	return DoorsLength;
}

