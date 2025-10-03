#pragma once

#include "CoreMinimal.h"

#include "Engine/GameInstance.h"

#include "%CLASS_PREFIX%GameInstance.generated.h"

/**
 * @class U%CLASS_PREFIX%GameInstance
 */
UCLASS()
class %MODULE_NAME_API%GAME_API U%CLASS_PREFIX%GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	U%CLASS_PREFIX%GameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
