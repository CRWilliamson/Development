// Created by Christopher Williamson
// A class that represents door information accessible by any class that controls doors.
// This is an empty class that does not represent any Unreal component or actor, this is because it only contains information and does not represent any tangible object in the editor. A similar alternative to this would be a struct.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CODETEST_API DoorInfo
{
public:
	DoorInfo();
	~DoorInfo();

	//Reference to the door itself whether it be an actor or a component.
	UObject* ObjectRef; 
	//A defined transform for when the door is open.
	FTransform OpenTransform; 
	//A defined transform for when the door is closed.
	FTransform CloseTransform; 
	//The interpolation start point.
	FTransform InterpStart; 
	//The interpolation end point.
	FTransform InterpTarget; 

};
