#pragma once
#include <vector>
#include <list>
#include "BaseScene.h"
#include "../common/Vector2.h"

struct Quadrangle
{
	Vector2f lt;
	Vector2f rt;
	Vector2f lb;
	Vector2f rb;
	int color;
};

#define lpSceneMng	SceneMng::GetInstance()

/// DrawGraph�p�̈����@(�O���t�B�b�N�n���h���Ax���W�A�����W)
using DrawQueT = std::tuple<int, int, int>;
/// DrawExtendGraph�p�̈��� (�O���t�B�b�N�n���h���A���㒸�_�����W�A���㒸�_�����W�A�E�����_�����W�A�E�����_�����W)
using DrawQueTEx = std::tuple<int, int, int, int, int>;

///@param IMAGE �O���t�B�b�N�n���h��
///@param X X���W
///@param Y Y���W
enum class DRAW_QUE
{
	IMAGE,
	X,
	Y
};


///@param IMAGE �O���t�B�b�N�n���h��
///@param X1 ���㒸�_X���W
///@param Y1 ���㒸�_X���W
///@param X2 �E�����_X���W
///@param Y2 �E�����_X���W
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

	int & GetTime(void);

	const Vector2 screenSize;
	const Vector2 gameScreenSize;
	const Vector2 gameScreenPos;
private:
	int _time;

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

	void ResetTime(void);
	bool SysInit(void);
	void Draw(void);
	std::list<Quadrangle> qaList;
	std::list<Quadrangle>::iterator itr;

	int colorPtn[4];
	int colorCnt;

	std::vector<DrawQueT> _drawList;
	std::vector<DrawQueTEx> _drawListEx;
};
