#pragma once

#include "CoreMinimal.h"

#include "Engine/LocalPlayer.h"

#include "%CLASS_PREFIX%LocalPlayer.generated.h"

/**
 * @class U%CLASS_PREFIX%LocalPlayer
 */
UCLASS()
class %MODULE_NAME_API%GAME_API U%CLASS_PREFIX%LocalPlayer : public ULocalPlayer
{
	GENERATED_BODY()
public:
	U%CLASS_PREFIX%LocalPlayer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
