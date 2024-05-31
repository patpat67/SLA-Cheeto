#include "cheat.h"
#include "global.h"
#include "HookManager.h"
#include "events.h"
#include "HotkeyManager.hpp"

#include "features/DamageHack.h"
#include "features/GodMode.h"

using namespace Cheat::Features;

static void GameFrameWork_Update_Hook(void* __this, MethodInfo* method);

void init_cheat()
{
#define INIT_FEATURE(feature) feature::GetInstance()
	INIT_FEATURE(DamageHack);
	INIT_FEATURE(GodMode);
#undef INIT_FEATURE

	HookManager::install(app::GameFrameWork_Update, GameFrameWork_Update_Hook);
}

void GameFrameWork_Update_Hook(void* __this, MethodInfo* method)
{
	SAFE_BEGIN();
	events::GameUpdateEvent();
	HotkeyManager::GetInstance().CheckForKeyPress();
	SAFE_EEND();
	CALL_ORIGIN(GameFrameWork_Update_Hook, __this, method);
}