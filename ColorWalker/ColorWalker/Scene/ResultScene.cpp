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
	lpSceneMng.addDrawQue({ IMAGE_ID("ÉäÉUÉãÉgÉçÉS")[0], 200, 100 });
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
