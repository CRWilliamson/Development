// Made by Christopher Williamson
// A class made to replace the default game mode so that I can set my own default classes.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodeTestGameModeBase.generated.h"

//

UCLASS()
class CODETEST_API ACodeTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	public:

		ACodeTestGameModeBase(const class FObjectInitializer& ObjectInitializer);	
};
