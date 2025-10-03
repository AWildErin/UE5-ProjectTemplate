#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "%CLASS_PREFIX%PlayerController.generated.h"

/**
 * @class A%CLASS_PREFIX%PlayerController
 */
UCLASS()
class A%CLASS_PREFIX%PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	A%CLASS_PREFIX%PlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
