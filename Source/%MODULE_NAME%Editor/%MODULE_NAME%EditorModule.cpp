#include "%MODULE_NAME%EditorModule.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "%MODULE_NAME%Editor"

DEFINE_LOG_CATEGORY(Log%PROJECT_SHORT_NAME%Editor);

void F%MODULE_NAME%EditorModule::StartupModule()
{
    UE_LOG(Log%PROJECT_SHORT_NAME%Editor, Log, TEXT("F%MODULE_NAME%EditorModule: Module Started"));
}

void F%MODULE_NAME%EditorModule::ShutdownModule()
{
    UE_LOG(Log%PROJECT_SHORT_NAME%Editor, Log, TEXT("F%MODULE_NAME%EditorModule: Module Ended"));
}

IMPLEMENT_MODULE(F%MODULE_NAME%EditorModule, %CLASS_PREFIX%Editor);

#undef LOCTEXT_NAMESPACE
