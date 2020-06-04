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
		_time++;
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

SceneMng::SceneMng() :screenSize({ 800,600 }), gameScreenSize({ 700,500 }), gameScreenPos({ (screenSize.x - gameScreenSize.x) / 2,(screenSize.y - gameScreenSize.y) / 2 })
{
}

SceneMng::~SceneMng()
{
}

void SceneMng::ResetTime(void)
{
	_time = 0;
}

bool SceneMng::SysInit(void)
{
	DxLib::SetGraphMode(800, 600, 16);
	DxLib::ChangeWindowMode(true);
	SetWindowText("ColorWalker");
	if (DxLib::DxLib_Init() == -1)
	{
		return false;
	}
	SET_IMAGE_ID("タイトルロゴ", "image/logo/titlelogo.png");
	SET_IMAGE_ID("リザルトロゴ", "image/logo/resultlogo.png");

	ImageMng::GetInstance().GetID("idle", "image/player/idle/idle.png", { 10,1 }, { 64,64 });
	ImageMng::GetInstance().GetID("run", "image/player/run/run.png", { 8,1 }, { 64,64 });
	ImageMng::GetInstance().GetID("jump", "image/player/jump/jump.png", { 10,1 }, { 64,64 });
	ImageMng::GetInstance().GetID("block", "image/tile/tile.png");

	ResetTime();
	colorPtn[0] = 0xffa0dd;
	colorPtn[1] = 0x00bfff;
	colorPtn[2] = 0xfffacd;
	colorPtn[3] = 0xfffafd;

	colorCnt = 0;

	qaList.push_back({ { 0,300 }, { 400,0 }, { 800,300 }, { 400,600 }, colorPtn[0] });
	qaList.push_back({ { 100,300 }, { 400,75 }, { 700,300 }, { 400,525 }, colorPtn[1] });
	qaList.push_back({ { 200,300 }, { 400,150 }, { 600,300 }, { 400,450 }, colorPtn[2] });
	qaList.push_back({ { 300,300 }, { 400,225 }, { 500,300 }, { 400,375 }, colorPtn[3] });
	return true;
}


void SceneMng::Draw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib::ClsDrawScreen();

	for (itr = qaList.begin(); itr != qaList.end(); itr++)
	{
		DrawQuadrangleAA((*itr).lt.x, (*itr).lt.y, (*itr).rt.x, (*itr).rt.y, (*itr).lb.x, (*itr).lb.y, (*itr).rb.x, (*itr).rb.y, (*itr).color, true);
		(*itr).lt.x -= 1.3f;
		(*itr).rt.y--;
		(*itr).lb.x += 1.3f;
		(*itr).rb.y++;
		if ((*itr).rt.y ==  0)
		{
			qaList.push_back({ {300,300},{400,225},{500,300},{400,375},colorPtn[colorCnt] });
			colorCnt++;
			if (colorCnt > 3)
			{
				colorCnt = 0;
			}
		}
	}

	if (qaList.front().rt.y < -375)
	{
		qaList.pop_front();
	}

	DrawBox(50, 50, 750, 550, 0x000000, true);

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

int & SceneMng::GetTime(void)
{
	return _time;
}
