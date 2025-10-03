#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameUserSettings.h"

#include "%CLASS_PREFIX%GameUserSettings.generated.h"

/**
 * @class U%CLASS_PREFIX%GameUserSettings
 */
UCLASS()
class %MODULE_NAME_API%GAME_API U%CLASS_PREFIX%GameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()
public:
	U%CLASS_PREFIX%GameUserSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
