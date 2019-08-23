// Made by Christopher Williamson


#include "PlayerPawn.h"
#include "Interactive/ClickableButton.h"
#include "CodeTest.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Possess the player upon startup.
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Set the root component.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Create the camera.
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));

	//Create the visible mesh.
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	//Attach the camera to the root in case it already isn't, and set its location and rotation.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	//Attach the mesh to the root in case it already isn't.
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Bind the action input named "LeftClick" defined in the config to the function GetMouseOverObject.
	PlayerInputComponent->BindAction("LeftClick",IE_Released,this,&APlayerPawn::GetMouseOverObject);

}

void APlayerPawn::GetMouseOverObject()
{
	//Create variables for the creen location of the mouse.
	float LocationX, LocationY;

	//Create a reference to the player controller.
	APlayerController* PC = Cast<APlayerController>(Controller);

	//Get the mouse position and assign to variables created earlier.
	PC->GetMousePosition(LocationX, LocationY);

	//Create a 2D vector using these variables.
	FVector2D ScreenPosition(LocationX, LocationY);

	//Create an empty hit result.
	FHitResult HitResult;

	//If we trace a line from the mouse position on the screen, does it hit anything?
	if (PC->GetHitResultAtScreenPosition(ScreenPosition, ECC_Visibility, false, HitResult) == true)
	{
		//If so, create a reference to the hit actor.
		AActor* HitActor = Cast<AActor>(HitResult.GetActor());

		//Create a reference to the class of the hit actor.
		UClass* HitClass = HitActor->GetClass();

		//Check if HitClass implements UUserInputInterface.
		bool bIsImplemented = HitClass->ImplementsInterface(UUserInputInterface::StaticClass());

		//If true, cast to that interface and call LeftMouseDown().
		if (bIsImplemented)
		{
			IUserInputInterface* InterfaceRef = Cast<IUserInputInterface>(HitActor);
			InterfaceRef->LeftMouseDown();
		}
	}


	return;
}

