#pragma once
#include <vector>
#include "BaseScene.h"
class ResultScene :
	public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	unique_Base Update(unique_Base own);
	SCN_ID GetScnID(void);
	void Init(void);
	void Draw(void);
private:
	std::vector<char> _push;
	std::vector<char> _clear;
};

