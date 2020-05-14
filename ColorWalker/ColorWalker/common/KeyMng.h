#pragma once
#include <vector>
#include <type_traits>
#include "InputState.h"
#define lpKeyMng KeyMng::GetInstance()

class KeyMng : public InputState
{
public:
	KeyMng();
	~KeyMng();

	void Update(void) override;
private:
	char _buf[256];
	
	std::vector<int> _confKey;

	INPUT_ID confID;

	int _lastKey;

	void(KeyMng::*func)(void);

};