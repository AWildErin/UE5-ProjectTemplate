#include "Core/%CLASS_PREFIX%GameModeBase.h"

#include "Core/%CLASS_PREFIX%GameStateBase.h"
#include "Player/%CLASS_PREFIX%PlayerController.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(%CLASS_PREFIX%GameModeBase)

#define LOCTEXT_NAMESPACE "%CLASS_PREFIX%GameModeBase"

A%CLASS_PREFIX%GameModeBase::A%CLASS_PREFIX%GameModeBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// here you can specify your custom HUD class and other things specific for the game mode

	GameStateClass = A%CLASS_PREFIX%GameStateBase::StaticClass();
	PlayerControllerClass = A%CLASS_PREFIX%PlayerController::StaticClass();
}

#undef LOCTEXT_NAMESPACE
