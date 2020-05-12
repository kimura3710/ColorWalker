#pragma once
#include <vector>
#include "BaseScene.h"
class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base Update(unique_Base own);
	void Init(void);
	SCN_ID GetScnID(void);
	void Draw(void);
private:
	std::vector<char> _push;
	std::vector<char> _galaga;
};

