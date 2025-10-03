#pragma once

#include "GameFramework/CheatManager.h"

#include "%CLASS_PREFIX%CheatManager.generated.h"

/**
 * @class U%CLASS_PREFIX%CheatManager
 */
UCLASS(config = Game, Within = PlayerController, MinimalAPI)
class U%CLASS_PREFIX%CheatManager : public UCheatManager
{
	GENERATED_BODY()
};
