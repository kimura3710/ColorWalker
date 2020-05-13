#include "Obj.h"
#include "../Scene/SceneMng.h"

Obj::Obj()
{
}

Obj::~Obj()
{
}

bool Obj::OutOfScreen(void)
{
	return false;
}

void Obj::SetAnimCnt(void)
{
	_animCnt = (int)lpSceneMng.GetTime() % GetLastAnim();
}

int Obj::GetLastAnim(void)
{
	return _animMap[_animKey][_animMap[_animKey].size() - 1].second;
}

bool Obj::SetAnim(const ANIM_TYPE & key, AnimVector & data)
{
	return _animMap.try_emplace(key,std::move(data)).second;
}
