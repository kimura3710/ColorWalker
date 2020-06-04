#include <DxLib.h>
#include <memory>
#include <algorithm>
#include "MainScene.h"
#include "SceneMng.h"
#include "ResultScene.h"
#include "../Obj/Obj.h"
#include "../Obj/Player.h"
#include "../Obj/Block/Block.h"

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

	for (auto & data : _objList)
	{
		data->Update();
		data->Obj::HitCheck(_objList);
		
	}

	if (pl->OutOfScreen() == true)
	{
		return std::move(std::make_unique<ResultScene>());
	}

	Draw();

	return std::move(own);
}

void MainScene::Init(void)
{
	_ghGameScreen = DxLib::MakeScreen(lpSceneMng.gameScreenSize.x, lpSceneMng.gameScreenSize.y, true);
	pl = new Player({ (double)(lpSceneMng.gameScreenSize.x / 2),(double)(lpSceneMng.gameScreenSize.y/2) });
	
	_objList.emplace_back(pl);

	bl = new Block({ (double)500,(double)(lpSceneMng.gameScreenSize.y - 32-128) });
	_objList.emplace_back(bl);
	
	for (auto j = 0; j < 10; j++)
	{
		bl = new Block({ (double)(((j + 1) * 64)  - 32),(double)(lpSceneMng.gameScreenSize.y - 32) });
		_objList.emplace_back(bl);
	}
}

SCN_ID MainScene::GetScnID(void)
{
	return SCN_ID::GAME;
}

void MainScene::Draw(void)
{
	int ghBefor;
	ghBefor = DxLib::GetDrawScreen();
	DxLib::SetDrawScreen(_ghGameScreen);
	DxLib::ClsDrawScreen();

	for (auto & data : _objList)
	{
		auto a = data;
		(*data).Obj::Draw();
	}

	SceneMng::GetInstance().addDrawQue({ _ghGameScreen,lpSceneMng.gameScreenPos.x,lpSceneMng.gameScreenPos.y });
	DxLib::SetDrawScreen(ghBefor);
}

