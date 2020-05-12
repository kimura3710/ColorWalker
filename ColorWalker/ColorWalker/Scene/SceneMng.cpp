#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "MainScene.h"
#include "ResultScene.h"

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
		SpaceKeyOld = SpaceKeyNow;
		SpaceKeyNow = DxLib::CheckHitKey(KEY_INPUT_SPACE);

		_activeScene = _activeScene->Update(move(_activeScene));

		//Draw();
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
	SetWindowText("1701312_ñÿë∫êêêl");
	///
	SetDrawScreen(DX_SCREEN_BACK);
	///

	if (DxLib::DxLib_Init() == -1)
	{
		return false;
	}
	return true;
}

void SceneMng::Draw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib::ClsDrawScreen();
	DxLib::ScreenFlip();
}
