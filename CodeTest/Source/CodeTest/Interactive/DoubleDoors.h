// Created by Christopher Williamson
// A class that represents a pair of doors that can be opened and closed. Reuses functionality from MovingDoor in order to do so.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Interactive/MovingDoor.h"
#include "Interactive/DoorInfo.h"
#include <array>
#include "DoubleDoors.generated.h"

//Inherits from AMovingDoor to gain access to all the state change and open/closing functionality.

UCLASS()
class CODETEST_API ADoubleDoors : public AMovingDoor
{
	GENERATED_BODY()

	public:

		ADoubleDoors();
		~ADoubleDoors();

		/*ADoubleDoors uses two static mesh components attached to a root, unlike MovingDoor that is a single static mesh component that also serves as the root of the actor.
		* Because of this, certain functions have to be overridden to account for the changes. They serve the same purpose, but will use different information.
		*/
		virtual bool IsDoorMotionComplete() override;
		virtual void PopulateDoorInfo() override;
		virtual DoorInfo* GetDoors() override;
		virtual int GetDoorsLength() override;

		//ADoubleDoors has two doors.
		int DoorsLength = 2;
		//Doors is declared in DoubleDoors to account for the second door. It will be returned by GetDoors() instead of the MovingDoor version as it will be incorrect.
		DoorInfo Doors[2];
		
		//Create a new scene component, this will become the new root and the doors will move on relative transforms.
		UPROPERTY(Category = SceneComponent, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* SceneComponent;

		//Create a new static mesh component, this will represent the second door.
		UPROPERTY(Category = StaticMeshComponent, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* RightDoor;

		//The open transform for the second door, can be changed in the editor.
		UPROPERTY(EditAnywhere)
		FTransform SecondDoorOpenTransform;
	
};
