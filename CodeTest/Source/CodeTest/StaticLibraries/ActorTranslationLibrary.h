// Made by Christopher Williamson
// This class will act as an example of a static library other classes can use to handle interpolated movement, both interpolating the values and setting actor and component transforms.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActorTranslationLibrary.generated.h"

UCLASS()
class CODETEST_API UActorTranslationLibrary : public UObject
{
	GENERATED_BODY()

	public:
		
		//Overloaded to account for object transform, location, and rotation values.
		//Parameter Target is of type UObject with the intention of casting as necessary as opposed to creating further overloads.
		static void InterpolateObjectMovement(UObject* Target, FTransform InterpStart, FTransform InterpTarget, float InterpDelta, float InterpSpeed);
		static void InterpolateObjectMovement(UObject* Target, FVector InterpStart, FVector InterpTarget, float InterpDelta, float InterpSpeed);
		static void InterpolateObjectMovement(UObject* Target, FRotator InterpStart, FRotator InterpTarget, float InterpDelta, float InterpSpeed);
	
};
