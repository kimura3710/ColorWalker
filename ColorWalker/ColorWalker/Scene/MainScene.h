#pragma once
#include "BaseScene.h"
#include <vector>


class MainScene :
	public BaseScene
{
public:
	MainScene();
	~MainScene();
	unique_Base Update(unique_Base own)override final;
	void Init(void);
	SCN_ID GetScnID(void);
private:
	void Draw(void);
};

