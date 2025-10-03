#pragma once

#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(Log%PROJECT_SHORT_NAME%Editor, Log, All);

/**
 * @class F%MODULE_NAME%EditorModule
 */
class F%MODULE_NAME%EditorModule : public FDefaultGameModuleImpl
{
public:
	// Begin IModuleInterface Interface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	// End IModuleInterface Interface
};
