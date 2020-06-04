#include "KeyMng.h"
#include <DxLib.h>

KeyMng::KeyMng()
{
	_confKey.reserve(static_cast<size_t>(end(INPUT_ID())));
	_confKey.emplace_back(KEY_INPUT_LEFT);
	_confKey.emplace_back(KEY_INPUT_RIGHT);
	_confKey.emplace_back(KEY_INPUT_UP);
	_confKey.emplace_back(KEY_INPUT_DOWN);
	_confKey.emplace_back(KEY_INPUT_Z);
	_confKey.emplace_back(KEY_INPUT_X);
	_confKey.emplace_back(KEY_INPUT_A);
	_confKey.emplace_back(KEY_INPUT_S);

}

KeyMng::~KeyMng()
{
}

void KeyMng::Update(void)
{
	InputState::SetOld();
	DxLib::GetHitKeyStateAll(_buf);
	for (auto data : INPUT_ID())
	{
		state(data, _buf[_confKey[static_cast<int>(data)]]);
	}
}
