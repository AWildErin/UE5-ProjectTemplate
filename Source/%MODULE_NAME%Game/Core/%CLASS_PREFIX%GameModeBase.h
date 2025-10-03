#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"

#include "%CLASS_PREFIX%GameModeBase.generated.h"

/**
 * @class A%CLASS_PREFIX%GameModeBase
 */
UCLASS()
class %MODULE_NAME_API%GAME_API A%CLASS_PREFIX%GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	A%CLASS_PREFIX%GameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
