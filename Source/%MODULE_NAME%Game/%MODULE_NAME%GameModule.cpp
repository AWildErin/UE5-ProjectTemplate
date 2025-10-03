#include "%MODULE_NAME%GameModule.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(Log%PROJECT_SHORT_NAME%);

#define LOCTEXT_NAMESPACE "%MODULE_NAME%Game"

void F%MODULE_NAME%GameModule::StartupModule()
{
    UE_LOG(Log%PROJECT_SHORT_NAME%, Log, TEXT("F%MODULE_NAME%GameModule: Module Started"));
}

void F%MODULE_NAME%GameModule::ShutdownModule()
{
    UE_LOG(Log%PROJECT_SHORT_NAME%, Log, TEXT("F%MODULE_NAME%GameModule: Module Ended"));
}

IMPLEMENT_PRIMARY_GAME_MODULE( F%MODULE_NAME%GameModule, %CLASS_PREFIX%Game, "%CLASS_PREFIX%Game" );

#undef LOCTEXT_NAMESPACE
