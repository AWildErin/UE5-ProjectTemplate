#pragma once

#include "CoreMinimal.h"

#include "Engine/LevelScriptActor.h"

#include "%CLASS_PREFIX%LevelScriptActor.generated.h"

/**
 * @class A%CLASS_PREFIX%LevelScriptActor
 */
UCLASS()
class %MODULE_NAME_API%GAME_API A%CLASS_PREFIX%LevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	A%CLASS_PREFIX%LevelScriptActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());;
};
