#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "MainScene.h"
#include "ResultScene.h"
#include "../common/ImageMng.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng());

void SceneMng::Run(void)
{
	if (SysInit() == false)
	{
		DxLib::DxLib_End();
	}
	_activeScene = std::make_unique<TitleScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();
		_drawListEx.clear();
		SpaceKeyOld = SpaceKeyNow;
		SpaceKeyNow = DxLib::CheckHitKey(KEY_INPUT_SPACE);

		_activeScene = _activeScene->Update(move(_activeScene));

		Draw();

	}
	DxLib::DxLib_End();
	ScreenFlip();
}

SceneMng::SceneMng()
{
}

SceneMng::~SceneMng()
{
}

bool SceneMng::SysInit(void)
{
	DxLib::SetGraphMode(800, 600, 16);
	DxLib::ChangeWindowMode(true);
	SetWindowText("1701312_木村瑞人");
	if (DxLib::DxLib_Init() == -1)
	{
		return false;
	}
	SET_IMAGE_ID("タイトルロゴ", "image/logo/titlelogo.png");
	SET_IMAGE_ID("リザルトロゴ", "image/logo/resultlogo.png");
	return true;
}

void SceneMng::Draw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib::ClsDrawScreen();

	for (auto data : _drawList)
	{
		DxLib::DrawGraph(
			std::get<static_cast<int>(DRAW_QUE::X)>(data),
			std::get<static_cast<int>(DRAW_QUE::Y)>(data),
			std::get<static_cast<int>(DRAW_QUE::IMAGE)>(data),
			true);
	}
	for (auto data : _drawListEx)
	{
		DxLib::DrawExtendGraph(
			std::get<static_cast<int>(DRAW_QUE_EX::X1)>(data),
			std::get<static_cast<int>(DRAW_QUE_EX::Y1)>(data),
			std::get<static_cast<int>(DRAW_QUE_EX::X2)>(data),
			std::get<static_cast<int>(DRAW_QUE_EX::Y2)>(data),
			std::get<static_cast<int>(DRAW_QUE_EX::IMAGE)>(data),
			true
		);
	}
	DxLib::ScreenFlip();
}

bool SceneMng::addDrawQue(DrawQueT dQue)
{
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue) == -1)
	{
		return false;
	}
	_drawList.emplace_back(dQue);

	return true;
}

bool SceneMng::addDrawQueEx(DrawQueTEx dQueEx)
{

	if (std::get<static_cast<int>(DRAW_QUE_EX::IMAGE)>(dQueEx) == -1)
	{
		return false;
	}
	_drawListEx.emplace_back(dQueEx);
	
	return true;
}
