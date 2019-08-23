// Made by Christopher Williamson
// A class composed of a single static mesh with the purpose of moving open and closed when told to do so by an input. The static mesh, its material, and additional properties can be changed in the Unreal Engine Editor.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interfaces/InteractiveObjectInterface.h"
#include "GameFramework/Actor.h"
#include <map>
#include "Interactive/DoorInfo.h"
#include <array>
#include "MovingDoor.generated.h"

using namespace std;

 //Inherits from AStaticMeshActor so that we can access the static mesh component as well as actor methods.
 //Inherits from IInteractiveObjectInterface so that MovingDoor can receive state changes from input objects.

UCLASS()
class CODETEST_API AMovingDoor : public AStaticMeshActor, public IInteractiveObjectInterface 
{
	GENERATED_BODY()

	protected:

		//Initialise object information.
		virtual void BeginPlay() override;

	public:

		//Constructor and destructor.
		AMovingDoor();
		~AMovingDoor();
		
		// Called every frame
		virtual void Tick(float DeltaTime) override;	
		//From IInteractiveObjectInterface, sets the state of the object and acts according to whatever state is set.
		virtual void SetState(std::string StateToSet) override;

		//Primes the door for interpolation.
		virtual void StartDoorInterpolation(UObject* Target, FTransform TargetTransform, FTransform CurrentTransform, float InterpolationSpeed);
		//Will set the interpolation of all doors.
		virtual void InterpolateDoorTransform();
		//Called when the state is set to open.
		virtual void OpenDoor();
		//Called when the state is set to closed.
		virtual void CloseDoor();
		//Finds all doors and creates door objects for them.
		virtual void PopulateDoorInfo();
		//Getter for DoorInfor array Doors.
		virtual DoorInfo* GetDoors();
		//Getter for integer DoorsLength.
		virtual int GetDoorsLength();
		//Check if the door has completed its interpolation.
		virtual bool IsDoorMotionComplete();

		//The number of doors this class has.
		int DoorsLength = 1;
		
		//A value to represent what point in the interpolation the object is at.
		float InterpDelta;

		//Interpolation will be done on tick, this will act as a condition when checking if interpolation should be run.
		bool bIsDoorInterpolating; 
		
		//An array containing information on all doors.
		DoorInfo Doors[1];
		
		//An enumeration of the states of MovingDoor.
		static enum DoorStates {
			Open,
			Closed,
			ToggleOpen
		};

		//States are received as strings, and are mapped to the state enumeration.
		std::map<string, DoorStates> DoorStatesMap;

		//The open transform of the door, can be set in the editor so in theory a developer can have the door go anywhere when opened. This can mean opening wider or in different directions.
		UPROPERTY(EditAnywhere)
		FTransform DoorOpenTransform;

		//How fast the door should move when opening and closing. Can be changed in the editor.
		UPROPERTY(EditAnywhere)
		float DoorInterpSpeed;
	
};
