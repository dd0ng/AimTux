#include "autostrafe.h"

bool Settings::AutoStrafe::enabled = true;

void AutoStrafe::CreateMove(CUserCmd* cmd)
{
	if (!Settings::AutoStrafe::enabled)
		return;

	C_BasePlayer* localplayer = (C_BasePlayer*)entitylist->GetClientEntity(engine->GetLocalPlayer());

	if (localplayer->GetFlags() & FL_ONGROUND)
		return;

	if (localplayer->GetMoveType() == MOVETYPE_LADDER || localplayer->GetMoveType() == MOVETYPE_NOCLIP)
		return;

	if (localplayer->GetLifeState() != LIFE_ALIVE || localplayer->GetHealth() == 0)
		return;

	if (cmd->mousedx > 1 || cmd->mousedx < -1)
		cmd->sidemove = cmd->mousedx < 0.f ? -450.f : 450.f;
}
