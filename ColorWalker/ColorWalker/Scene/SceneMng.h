#pragma once
#include <vector>
#include "BaseScene.h"
#include "../common/Vector2.h"

#define lpSceneMng	SceneMng::GetInstance()

class SceneMng
{
public:
	static SceneMng &GetInstance(void)
	{
		return *s_Instance;
	}

	void Run(void);

	int SpaceKeyNow;
	int SpaceKeyOld;


private:
	struct SceneMngDeleter
	{
		void operator()(SceneMng * Smng)const
		{
			delete Smng;
		}
	};
	unique_Base _activeScene;
	SceneMng();
	~SceneMng();
	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;

	bool SysInit(void);
	void Draw(void);

};
