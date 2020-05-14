#include "InputState.h"



InputState::InputState()
{
	// {変数,変数}は初期化listでlistは要素数が確定していない
	// なので要素数を固定してあげる必要がある
	// 今回の場合はKeyPairで型を指定してあげる必要があった

	// 範囲for文は要素にする値のbeginとendが必要になる
	// 今回のINPUT_IDはenum classなので別にクラスを作成し、begin、end、ｲﾝｸﾘﾒﾝﾄ、ﾃﾞｸﾘﾒﾝﾄ、参照を作成すると
	// 範囲for文で回せるようになる
	// ただしenum classを型ｷｬｽﾄする場合は<type_traits>をｲﾝｸﾙｰﾄﾞする必要がある
	for (auto id : INPUT_ID())
	{
		_state.try_emplace(id, KeyPair{ 0, 1 });
	}
}

InputState::~InputState()
{
}

const KeyMap & InputState::state(void) const
{
	return _state;
}

bool InputState::state(INPUT_ID id, KeyMap state)
{
	if ((id < INPUT_ID::LEFT) || (INPUT_ID::MAX < id))
	{
		return false;
	}
	_state = state;
	return true;
}

const KeyPair InputState::state(INPUT_ID id) const
{
	try
	{
		return _state.at(id);
	}
	catch (...)
	{
	}
	
	return { 0, 0 };
}

bool InputState::state(INPUT_ID id, int data)
{
	if (_state.find(id) != _state.end())
	{
		_state[id].first = data;
		return true;
	}
	return false;
}

void InputState::SetOld(void)
{
	for (auto id : INPUT_ID())
	{
		try
		{
			_state[id].second = _state[id].first;
		}
		catch (...)
		{
			_state.emplace(id, KeyPair{ 0,1 });
		}
	}
}
