#include "Player/%CLASS_PREFIX%PlayerController.h"

#include "Player/%CLASS_PREFIX%CheatManager.h"

A%CLASS_PREFIX%PlayerController::A%CLASS_PREFIX%PlayerController(const FObjectInitializer& ObjectInitializer)
{
	CheatClass = U%CLASS_PREFIX%CheatManager::StaticClass();
}
