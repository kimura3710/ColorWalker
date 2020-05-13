#include <DxLib.h>
#include <memory>
#include <algorithm>
#include "MainScene.h"
#include "SceneMng.h"
#include "ResultScene.h"

MainScene::MainScene()
{
	MainScene::Init();
}

MainScene::~MainScene()
{
}

unique_Base MainScene::Update(unique_Base own)
{
	if (lpSceneMng.SpaceKeyNow == 1 && lpSceneMng.SpaceKeyOld == 0)
	{
		return std::move(std::make_unique<ResultScene>());
	}
	return std::move(own);
}

void MainScene::Init(void)
{
}

SCN_ID MainScene::GetScnID(void)
{
	return SCN_ID::GAME;
}

void MainScene::Draw(void)
{
}

