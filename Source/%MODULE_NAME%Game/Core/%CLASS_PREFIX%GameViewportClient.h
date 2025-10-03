#pragma once

#include "CoreMinimal.h"

#include "CommonGameViewportClient.h"

#include "%CLASS_PREFIX%GameViewportClient.generated.h"

/**
 * @class U%CLASS_PREFIX%GameViewportClient
 */
UCLASS()
class %MODULE_NAME_API%GAME_API U%CLASS_PREFIX%GameViewportClient : public UCommonGameViewportClient
{
	GENERATED_BODY()
public:
	U%CLASS_PREFIX%GameViewportClient(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
