#include "%CLASS_PREFIX%EditorEngine.h"

#include "%MODULE_NAME%EditorModule.h"

#include "ISourceControlModule.h"
#include "ISourceControlProvider.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(%CLASS_PREFIX%EditorEngine)

#define LOCTEXT_NAMESPACE "%CLASS_PREFIX%Editor"

U%CLASS_PREFIX%EditorEngine::U%CLASS_PREFIX%EditorEngine(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void U%CLASS_PREFIX%EditorEngine::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);

	UE_LOG(Log%PROJECT_SHORT_NAME%Editor, Log, TEXT("U%CLASS_PREFIX%EditorEngine: Init"));

	const ISourceControlModule& SourceControlModule = ISourceControlModule::Get();
	{
		/** @todo Get automatic merging working for branches*/
		ISourceControlProvider& SourceControlProvider = SourceControlModule.GetProvider();
		
		TArray<FString> Branches;
		GConfig->GetArray(TEXT("SourceControl"), TEXT("StatusBranches"), Branches, GEditorIni);
		SourceControlProvider.RegisterStateBranches(Branches, TEXT("Content"));
	}
}

void U%CLASS_PREFIX%EditorEngine::Start()
{
	Super::Start();

	UE_LOG(Log%PROJECT_SHORT_NAME%Editor, Log, TEXT("U%CLASS_PREFIX%EditorEngine: Start"));
}

void U%CLASS_PREFIX%EditorEngine::Tick(float DeltaSeconds, bool bIdleMode)
{
	Super::Tick(DeltaSeconds, bIdleMode);
}

#undef LOCTEXT_NAMESPACE
