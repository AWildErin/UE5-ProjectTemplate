#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameStateBase.h"

#include "%CLASS_PREFIX%GameStateBase.generated.h"

/**
 * @class A%CLASS_PREFIX%GameStateBase
 */
UCLASS()
class %MODULE_NAME_API%GAME_API A%CLASS_PREFIX%GameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	A%CLASS_PREFIX%GameStateBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
