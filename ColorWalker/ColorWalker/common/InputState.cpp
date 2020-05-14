#include "InputState.h"



InputState::InputState()
{
	// {�ϐ�,�ϐ�}�͏�����list��list�͗v�f�����m�肵�Ă��Ȃ�
	// �Ȃ̂ŗv�f�����Œ肵�Ă�����K�v������
	// ����̏ꍇ��KeyPair�Ō^���w�肵�Ă�����K�v��������

	// �͈�for���͗v�f�ɂ���l��begin��end���K�v�ɂȂ�
	// �����INPUT_ID��enum class�Ȃ̂ŕʂɃN���X���쐬���Abegin�Aend�A�ݸ���āA�޸���āA�Q�Ƃ��쐬�����
	// �͈�for���ŉ񂹂�悤�ɂȂ�
	// ������enum class���^���Ă���ꍇ��<type_traits>��ݸٰ�ނ���K�v������
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
