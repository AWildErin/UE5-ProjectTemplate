#pragma once

#include "CoreMinimal.h"

#include "Engine/AssetManager.h"

#include "%CLASS_PREFIX%AssetManager.generated.h"

/**
 * @class U%CLASS_PREFIX%AssetManager
 */
UCLASS(Config = Game)
class %MODULE_NAME_API%GAME_API U%CLASS_PREFIX%AssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	U%CLASS_PREFIX%AssetManager();
};
