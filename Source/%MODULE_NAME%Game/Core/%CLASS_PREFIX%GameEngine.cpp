#include "Core/%CLASS_PREFIX%GameEngine.h"

#include "%MODULE_NAME%GameModule.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(%CLASS_PREFIX%GameEngine)

#define LOCTEXT_NAMESPACE "%CLASS_PREFIX%GameEngine"

U%CLASS_PREFIX%GameEngine::U%CLASS_PREFIX%GameEngine(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void U%CLASS_PREFIX%GameEngine::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);

	UE_LOG(Log%PROJECT_SHORT_NAME%, Log, TEXT("U%CLASS_PREFIX%GameEngine: Init"));
}

void U%CLASS_PREFIX%GameEngine::Start()
{
	Super::Start();

	UE_LOG(Log%PROJECT_SHORT_NAME%, Log, TEXT("U%CLASS_PREFIX%GameEngine: Start"));
}

void U%CLASS_PREFIX%GameEngine::Tick(float DeltaSeconds, bool bIdleMode)
{
	Super::Tick(DeltaSeconds, bIdleMode);
}

#undef LOCTEXT_NAMESPACE
