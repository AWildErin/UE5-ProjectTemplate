#pragma once

#include "CoreMinimal.h"

#include "GameFramework/WorldSettings.h"

#include "%CLASS_PREFIX%WorldSettings.generated.h"

/**
 * @class A%CLASS_PREFIX%WorldSettings
 */
UCLASS()
class %MODULE_NAME_API%GAME_API A%CLASS_PREFIX%WorldSettings : public AWorldSettings
{
	GENERATED_BODY()
public:
	A%CLASS_PREFIX%WorldSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
