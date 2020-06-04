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
	std::vector<int> _confKey;
	INPUT_ID confID;
	char _buf[256];	
	int _lastKey;

};