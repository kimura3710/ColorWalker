#pragma once
#include <map>
#include "INPUT_ID.h"

using KeyPair = std::pair<int, int>;
using KeyMap = std::map<INPUT_ID, KeyPair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();
	virtual void Update(void) = 0;
	const KeyMap &state(void)const;
	bool state(INPUT_ID id, KeyMap state);
	const KeyPair state(INPUT_ID id)const;
	bool state(INPUT_ID id, int data);
	void SetOld(void);
private:
	KeyMap _state;
};

