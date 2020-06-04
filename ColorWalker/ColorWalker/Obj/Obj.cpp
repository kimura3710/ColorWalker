#include "Obj.h"
#include <DxLib.h>
#include "../Scene/SceneMng.h"

Obj::Obj()
{
	left = 0;
	up = 0;
	right = 700;
	down = 500;
}

Obj::~Obj()
{
}

void Obj::Draw(void)
{
	if (_animMap.find(_animKey) == _animMap.end())
	{
		return;
	}
	if (_animMap[_animKey].size() <= _animID)
	{
		return;
	}

	if (_animCnt >= _animMap[_animKey][_animID].second)
	{
		if (_animMap[_animKey][_animID].first != -1)
		{
			_animID++;
		}
		if (_animID >= _animMap[_animKey].size())
		{
			_animID = 0;
			_animCnt = 0;
		}
	}
	DxLib::DrawRotaGraph((int)_pos.x, (int)_pos.y, 1.0, 0, _animMap[_animKey][_animID].first, true, _turnFlag);
	_animCnt++;
}

bool Obj::OutOfScreen(void)
{
	if (_pos.x <= (left + _size.x / 2))
	{
		return true;
	}
	else if (_pos.x >= (right - _size.x / 2))
	{
		return true;
	}

	if (_pos.y <= (up + _size.y / 2))
	{
		return true;
	}
	else if (_pos.y >= (down - _size.y / 2))
	{
		return true;
	}
	return false;
}

void Obj::CheckGameScreen(Vector2d & pos)
{
	if (pos.x <= (left + _size.x / 2))
	{
		pos.x = (left + _size.x / 2);
	}
	else if (pos.x >= (right - _size.x / 2))
	{
		pos.x = (right - _size.x / 2);
	}

	if (pos.y <= (up + _size.y / 2))
	{
		pos.y = (up + _size.y / 2);
	}
	else if (pos.y >= (down - _size.y / 2))
	{
		pos.y = (down - _size.y / 2);
	}
}

void Obj::SetAnimCnt(void)
{
	_animCnt = (int)lpSceneMng.GetTime() % GetLastAnim();
}

int Obj::GetLastAnim(void)
{
	return _animMap[_animKey][_animMap[_animKey].size() - 1].second;
}

bool Obj::ChangeAnim(const ANIM_TYPE animKey)
{
	if ((animKey < ANIM_TYPE::IDLE) || (ANIM_TYPE::MAX < animKey))
	{
		return false;
	}
	if (_animKey != animKey)
	{
		_animID = 0;
		_animCnt = 0;
	}
	_animKey = animKey;
	return true;
}

bool Obj::HitCheck(const std::vector<sharedObj> & _objList)
{
	for (auto & data : _objList)
	{
		/*if (data->GetObjType() == this->GetObjType() || data->IsAlive() == false)
		{
			return false;
		}*/

		if ((abs(data->GetPos().x - this->GetPos().x) < ((this->GetSize().x  + data->GetSize().x) / 2)) &&
			(abs(data->GetPos().y - this->GetPos().y) < ((this->GetSize().y  + data->GetSize().y) / 2)))
		{
			if (this->GetObjType() == OBJ_TYPE::PLAYER)
			{
				
				if (this->GetObjType() == data->GetObjType())
				{
					return false;
				}
				else if (this->GetObjType() != data->GetObjType())
				{
					return true;
				}
			}
			else if (this->GetObjType() != data->GetObjType())
			{
				if (data->GetObjType() == OBJ_TYPE::PLAYER)
				{
					data->_isAir = false;
				}
				this->_alive = false;
				data->_alive = false;
			}
		}
	}
	return false;
}

const Vector2d Obj::GetPos(void) const
{
	return _pos;
}

const Vector2 Obj::GetSize(void) const
{
	return _size;
}

COLOR_TYPE Obj::GetColor(void)
{
	return colorType;
}

bool Obj::SetAnim(const ANIM_TYPE & key, AnimVector & data)
{
	return _animMap.try_emplace(key,std::move(data)).second;
}
