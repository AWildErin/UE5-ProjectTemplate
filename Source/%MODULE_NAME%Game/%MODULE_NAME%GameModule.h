#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(Log%PROJECT_SHORT_NAME%, Log, All);

/**
 * @class F%MODULE_NAME%GameModule
 */
class F%MODULE_NAME%GameModule : public FDefaultGameModuleImpl
{
public:
	// Begin IModuleInterface Interface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	// End IModuleInterface Interface
};
