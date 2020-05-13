#include<DxLib.h>
#include "TitleScene.h"
#include "MainScene.h"
#include "SceneMng.h"
#include "../common/ImageMng.h"


TitleScene::TitleScene()
{
	TitleScene::Init();
}


TitleScene::~TitleScene()
{
}

unique_Base TitleScene::Update(unique_Base own)
{
	lpSceneMng.addDrawQue({ IMAGE_ID("É^ÉCÉgÉãÉçÉS")[0],200,150 });
	if (lpSceneMng.SpaceKeyNow == 1 && lpSceneMng.SpaceKeyOld == 0)
	{
 		return std::move(std::make_unique<MainScene>());
	}
	return std::move(own);
}

void TitleScene::Init(void)
{
}
	

SCN_ID TitleScene::GetScnID(void)
{
	return SCN_ID::TITLE;
}

void TitleScene::Draw(void)
{
}
