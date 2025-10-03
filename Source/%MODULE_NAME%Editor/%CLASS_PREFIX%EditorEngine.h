#pragma once

#include "Editor/UnrealEdEngine.h"

#include "%CLASS_PREFIX%EditorEngine.generated.h"

class IEngineLoop;

/**
 * @class U%CLASS_PREFIX%EditorEngine
 */
UCLASS()
class U%CLASS_PREFIX%EditorEngine : public UUnrealEdEngine
{
	GENERATED_BODY()

public:
	U%CLASS_PREFIX%EditorEngine(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
    // Begin UEngine interface
	virtual void Init(IEngineLoop* InEngineLoop) override;
	virtual void Start() override;
	virtual void Tick(float DeltaSeconds, bool bIdleMode) override;
    // End UEngineInterface
};
