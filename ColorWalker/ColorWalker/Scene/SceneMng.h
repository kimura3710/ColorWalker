#pragma once
#include <vector>
#include "BaseScene.h"
#include "../common/Vector2.h"

#define lpSceneMng	SceneMng::GetInstance()

/// DrawGraph用の引数　(グラフィックハンドル、x座標、ｙ座標)
using DrawQueT = std::tuple<int, int, int>;
/// DrawExtendGraph用の引数 (グラフィックハンドル、左上頂点ｘ座標、左上頂点ｙ座標、右下頂点ｘ座標、右下頂点ｙ座標)
using DrawQueTEx = std::tuple<int, int, int, int, int>;

///@param IMAGE グラフィックハンドル
///@param X X座標
///@param Y Y座標
enum class DRAW_QUE
{
	IMAGE,
	X,
	Y
};


///@param IMAGE グラフィックハンドル
///@param X1 左上頂点X座標
///@param Y1 左上頂点X座標
///@param X2 右下頂点X座標
///@param Y2 右下頂点X座標
enum class DRAW_QUE_EX
{
	IMAGE,
	X1,
	Y1,
	X2,
	Y2
};


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

	bool addDrawQue(DrawQueT dQue);
	bool addDrawQueEx(DrawQueTEx dQueEx);
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

	std::vector<DrawQueT> _drawList;
	std::vector<DrawQueTEx> _drawListEx;
};
