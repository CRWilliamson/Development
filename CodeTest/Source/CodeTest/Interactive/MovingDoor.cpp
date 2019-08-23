// Created by Christopher Williamson

#include "MovingDoor.h"
#include "StaticLibraries/ActorTranslationLibrary.h"

AMovingDoor::AMovingDoor() : Super()
{
	//Enable tick
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bAllowTickOnDedicatedServer = true;

	//Map strings to state enumeration.
	DoorStatesMap["Open"] = Open;
	DoorStatesMap["Closed"] = Closed;
	DoorStatesMap["ToggleOpen"] = ToggleOpen;
}

AMovingDoor::~AMovingDoor()
{
	
	
}

void AMovingDoor::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(true);

	//Get all the information we can on the door
	PopulateDoorInfo();

	//Set InterpDelta to a proportion of 1.0. This will be used at the start of interpolation to determine how long InterpDelta should increase before interpolation is deemed complete.
	InterpDelta = 1.0f / DoorInterpSpeed;
	
}

void AMovingDoor::PopulateDoorInfo()
{
	//Set door properties. Each door needs to remember its open and closed positions.
	GetDoors()[0].ObjectRef = Cast<UObject>(this);
	GetDoors()[0].CloseTransform = GetActorTransform();
	GetDoors()[0].OpenTransform = DoorOpenTransform;

}

void AMovingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Is interpolation enabled?
	if (bIsDoorInterpolating)
	{
		//If so, add frame time to InterpDelta and use that to move the door.
		InterpDelta += DeltaTime;
		InterpolateDoorTransform();

		//After movement, is door motion complete?
		if (IsDoorMotionComplete())
		{
			//If so, end interpolation.
			bIsDoorInterpolating = false;
		}
		
	}
}

void AMovingDoor::StartDoorInterpolation(UObject* Target, FTransform TargetTransform, FTransform CurrentTransform, float InterpolationSpeed)
{
	//Is the door not already interpolating?
	if (!bIsDoorInterpolating)
	{
		//If so, initialise InterpDelta.
		InterpDelta = FMath::Clamp(((1.0f / InterpolationSpeed) - InterpDelta),0.0f, (1.0f / InterpolationSpeed));
		//Set interpolation speed.
		DoorInterpSpeed = InterpolationSpeed;
	}
	
	//We're going to loop through all the doors.
	for (int i = 0; i < GetDoorsLength(); i++)
	{
		//Is this door the same as parameter Target?
		if (GetDoors()[i].ObjectRef == Target)
		{
			//If so, set InterpStart and InterpTarget
			GetDoors()[i].InterpStart = CurrentTransform;
			GetDoors()[i].InterpTarget = TargetTransform;
		}
	}
	//Enable interpolation.
	bIsDoorInterpolating = true;

	return;
}

void AMovingDoor::InterpolateDoorTransform()
{
	//We're going to loop through all the doors.
	for (int i = 0; i < GetDoorsLength(); i++)
	{
		//For each door, call InterpolatObjectMovement using values obtained from the door's properties.
		UActorTranslationLibrary::InterpolateObjectMovement(GetDoors()[i].ObjectRef, GetDoors()[i].InterpStart, GetDoors()[i].InterpTarget, InterpDelta, DoorInterpSpeed);
	}
	
}

void AMovingDoor::OpenDoor()
{
	
	//Disable interpolation.
	bIsDoorInterpolating = false;

	//Loop through all the doors.
	for (int i = 0; i < GetDoorsLength(); i++)
	{
		//Start interpolation on each door we loop through.
		StartDoorInterpolation(GetDoors()[i].ObjectRef, GetDoors()[i].OpenTransform, GetDoors()[i].CloseTransform, DoorInterpSpeed);
	}
}

void AMovingDoor::CloseDoor()
{
	//Disable interpolation.
	bIsDoorInterpolating = false;
	for (int i = 0; i < GetDoorsLength(); i++)
	{
		//Start interpolation on each door we loop through.
		StartDoorInterpolation(GetDoors()[i].ObjectRef, GetDoors()[i].CloseTransform, GetDoors()[i].OpenTransform, DoorInterpSpeed);
	}
}

bool AMovingDoor::IsDoorMotionComplete()
{
	//Check if the actor transform is the same as the interpolation target and return the result.
	return GetActorTransform().Equals(GetDoors()[0].InterpTarget, 0.0001);
}

void AMovingDoor::SetState(std::string StateToSet)
{
	
	IInteractiveObjectInterface::SetState(StateToSet);

	//Run the appropriate code for whatever state that came through.
	switch (DoorStatesMap[StateToSet])
	{
		case Open:
			OpenDoor();
			break;

		case Closed:
			CloseDoor();
			break;

		case ToggleOpen:  
			if (GetDoors()[0].InterpTarget.Equals(GetDoors()[0].OpenTransform, 0.000001))
				CloseDoor();
			else
				OpenDoor();
			break;
	}
	return;
}

DoorInfo* AMovingDoor::GetDoors()
{
	//Return array Doors.
	return Doors;
}

int AMovingDoor::GetDoorsLength()
{
	//Return the length of array Doors.
	return DoorsLength;
}
