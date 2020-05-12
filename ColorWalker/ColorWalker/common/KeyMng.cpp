#include "KeyMng.h"
#include <DxLib.h>

int KeyMng::GetNowKey(int keyId)
{
	return nowKey[keyId];
}

int KeyMng::GetOldKey(int keyId)
{
	return oldKey[keyId];
}

bool KeyMng::IsPressing(int keyId) const
{
	return (keyState & keyId);
}

bool KeyMng::IsTringger(int keyId) const
{
	return (!(oldKeyState & keyId) && (keyState & keyId));
}

KeyMng::KeyMng()
{
}

KeyMng::~KeyMng()
{
}

void KeyMng::KeyUpdate(void)
{
	keyState = oldKeyState;
	oldKeyState = DxLib::CheckHitKeyAll(DX_CHECKINPUT_KEY);
}
