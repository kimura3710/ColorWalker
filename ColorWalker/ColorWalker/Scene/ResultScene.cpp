#include <DxLib.h>
#include "ResultScene.h"
#include "TitleScene.h"
#include "SceneMng.h"
#include "../common/ImageMng.h"


ResultScene::ResultScene()
{
	ResultScene::Init();
}


ResultScene::~ResultScene()
{
}

unique_Base ResultScene::Update(unique_Base own)
{
	DxLib::ClsDrawScreen();
	DxLib::DrawString(400, 300, "リザルトシーン", 0xffffff, true);
	DxLib::ScreenFlip();
	if (lpSceneMng.SpaceKeyNow == 1 && lpSceneMng.SpaceKeyOld == 0)
	{
		return std::move(std::make_unique<TitleScene>());
	}

	return std::move(own);
}

SCN_ID ResultScene::GetScnID(void)
{
	return SCN_ID::RESULT;
}

void ResultScene::Init(void)
{
	
}

void ResultScene::Draw(void)
{
}
