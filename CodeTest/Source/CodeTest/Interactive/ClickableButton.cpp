// Made by Christopher Williamson

#include "ClickableButton.h"

AClickableButton::AClickableButton() : Super()
{
	//Enable tick
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bAllowTickOnDedicatedServer = true;

}

void AClickableButton::BeginPlay()
{
	Super::BeginPlay();
}

void AClickableButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AClickableButton::LeftMouseDown()
{
	//Loop through the array of instructions.
	for (int i = 0;i < InstructionsOnClick.Num();i++)
	{
		//Call SendState using the Target and State to set that should have been defined in the Unreal Editor.
		SendState(InstructionsOnClick[i].Target, InstructionsOnClick[i].StateToSet);
	}

	return;
}