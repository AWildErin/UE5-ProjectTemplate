#pragma once

#include "CoreMinimal.h"

#include "Engine/GameEngine.h"

#include "%CLASS_PREFIX%GameEngine.generated.h"

/**
 * @class U%CLASS_PREFIX%GameEngine
 */
UCLASS()
class %MODULE_NAME_API%GAME_API U%CLASS_PREFIX%GameEngine : public UGameEngine
{
	GENERATED_BODY()

public:
	U%CLASS_PREFIX%GameEngine(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	// Begin UEngine interface
	virtual void Init(class IEngineLoop* InEngineLoop) override;
	virtual void Start() override;
	virtual void Tick(float DeltaSeconds, bool bIdleMode) override;
	// End UEngine interface
};
