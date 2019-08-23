// Made by Christopher Williamson

#include "CodeTestGameModeBase.h"
#include "Player/PlayerPawn.h"
#include "Player/PawnController.h"

ACodeTestGameModeBase::ACodeTestGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//Set the default player controller.
	PlayerControllerClass = APawnController::StaticClass();

	//Set the default pawn.
	DefaultPawnClass = APlayerPawn::StaticClass();
}