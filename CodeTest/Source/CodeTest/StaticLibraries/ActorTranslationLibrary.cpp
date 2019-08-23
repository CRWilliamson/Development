// Created by Christopher Williamson

#include "ActorTranslationLibrary.h"
#include "GameFramework\Actor.h"
#include "Components/StaticMeshComponent.h"

void UActorTranslationLibrary::InterpolateObjectMovement(UObject* Target, FTransform InterpStart, FTransform InterpTarget, float InterpDelta, float InterpSpeed)
{
	//Create variable HitResult to be used by SetActorTransform
	FHitResult HitResult;

	//If Target can be cast to AActor then we want to move an actor as opposed to a component.
	if (Cast<AActor>(Target))
	{
		//Cast to AActor, then set the actor transform to an interpolated value between InterpStart and InterpTarget at point InterpDelta at speed InterpSpeed
		Cast<AActor>(Target)->SetActorTransform(FTransform(FMath::QInterpTo(InterpStart.GetRotation(), InterpTarget.GetRotation(), InterpDelta, InterpSpeed),
			FMath::VInterpTo(InterpStart.GetLocation(), InterpTarget.GetLocation(), InterpDelta, InterpSpeed),
			FMath::VInterpTo(InterpStart.GetScale3D(), InterpTarget.GetScale3D(), InterpDelta, InterpSpeed)), false, &HitResult, ETeleportType::None);
	}
	else
	{
		//If Target can be cast to USceneComponent then we want to move a component as opposed to an actor
		if (Cast<USceneComponent>(Target))
		{
			Cast<USceneComponent>(Target)->SetRelativeTransform(FTransform(FMath::QInterpTo(InterpStart.GetRotation(), InterpTarget.GetRotation(), InterpDelta, InterpSpeed),
				FMath::VInterpTo(InterpStart.GetLocation(), InterpTarget.GetLocation(), InterpDelta, InterpSpeed),
				FMath::VInterpTo(InterpStart.GetScale3D(), InterpTarget.GetScale3D(), InterpDelta, InterpSpeed)), false, &HitResult, ETeleportType::None);
		}
	}

	return;
}

void UActorTranslationLibrary::InterpolateObjectMovement(UObject* Target, FVector InterpStart, FVector InterpTarget, float InterpDelta, float InterpSpeed)
{
	FHitResult HitResult;
	if (Cast<AActor>(Target))
	{
		Cast<AActor>(Target)->SetActorLocation(FMath::VInterpTo(InterpStart, InterpTarget, InterpDelta, InterpSpeed), false, &HitResult, ETeleportType::None);
	}

	return;
}

void UActorTranslationLibrary::InterpolateObjectMovement(UObject* Target, FRotator InterpStart, FRotator InterpTarget, float InterpDelta, float InterpSpeed)
{
	if (Cast<AActor>(Target))
	{
		Cast<AActor>(Target)->SetActorRotation(FMath::QInterpTo(InterpStart.Quaternion(), InterpTarget.Quaternion(), InterpDelta, InterpSpeed), ETeleportType::None);
	}

	return;
}
