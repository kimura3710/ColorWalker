#include "Player.h"
#include "../common/InputState.h"
#include "../common/KeyMng.h"

Player::Player()
{
}

Player::Player(Vector2d pos)
{
	_pos = pos;
	_size = { 64,64 };
	_alive = true;
	_turnFlag = false;
	Player::Init();

	_updater = &Player::IdleUpdate;
}

Player::~Player()
{
}

void Player::Update(void)
{
	(*input).Update();
	(this->*_updater)();
	if (_isAir)
	{
		_vel.y += 0.5;
	}
	_pos += _vel;

	//Obj::CheckGameScreen(_pos);
}

void Player::Draw(void)
{
}

OBJ_TYPE Player::GetObjType(void)
{
	return OBJ_TYPE::PLAYER;
}

void Player::Landing(void)
{
	_vel.x = 0;
	_vel.y = 0;
	_isAir = false;
	_updater = &Player::IdleUpdate;
	Obj::ChangeAnim(ANIM_TYPE::IDLE);
}


bool Player::Init(void)
{
	AnimVector data;

	data.reserve(10);
	for (auto j = 0; j < 10; j++)
	{
		data.emplace_back(IMAGE_ID("idle")[j], 5 * (j + 1));
	}
	Obj::SetAnim(ANIM_TYPE::IDLE, data);

	data.reserve(10);
	for (auto j = 0; j < 10; j++)
	{
		data.emplace_back(IMAGE_ID("jump")[j], 5 * (j + 1));
	}
	Obj::SetAnim(ANIM_TYPE::JUMP, data);

	data.reserve(8);
	for (auto j = 0; j < 8; j++)
	{
		data.emplace_back(IMAGE_ID("run")[j], 5 * (j + 1));
	}
	Obj::SetAnim(ANIM_TYPE::RUN, data);


	input = std::make_unique<KeyMng>();
	return true;
}

void Player::IdleUpdate(void)
{
	if ((*input).state(INPUT_ID::LEFT).first || (*input).state(INPUT_ID::RIGHT).first)
	{
		Obj::ChangeAnim(ANIM_TYPE::RUN);
		_updater = &Player::WalkUpdate;
	}
	if ((*input).state(INPUT_ID::BTN_1).first && _isAir == false)
	{
		_vel.y = -13.0f;
		_isAir = true;
		Obj::ChangeAnim(ANIM_TYPE::JUMP);
		_updater = &Player::JumpUpdate;
	}
}

void Player::WalkUpdate(void)
{
	if ((*input).state(INPUT_ID::LEFT).first)
	{
		_turnFlag = true;
		_vel.x = -1;
		if ((*input).state(INPUT_ID::BTN_1).first && _isAir == false)
		{
			_vel.y = -13.0f;
			_isAir = true;
			Obj::ChangeAnim(ANIM_TYPE::JUMP);
			_updater = &Player::JumpUpdate;
		}
	}
	else if ((*input).state(INPUT_ID::RIGHT).first)
	{
		_turnFlag = false;
		_vel.x = 1;		
		if ((*input).state(INPUT_ID::BTN_1).first && _isAir == false)
		{
			_vel.y = -13.0f;
			_isAir = true;
			Obj::ChangeAnim(ANIM_TYPE::JUMP);
			_updater = &Player::JumpUpdate;
		}
	}	
	else
	{
		_vel.x = 0;
		_updater = &Player::IdleUpdate;
		Obj::ChangeAnim(ANIM_TYPE::IDLE);
	}
}

void Player::JumpUpdate(void)
{
	if ((*input).state(INPUT_ID::LEFT).first)
	{
		_turnFlag = true;
		_vel.x = -1;
	}
	else if ((*input).state(INPUT_ID::RIGHT).first)
	{
		_turnFlag = false;
		_vel.x = 1;
	}

	if (_isAir == false)
	{
		Landing();
	}
	
	/*if (_pos.y >= 450 -25)
	{
		_isAir = false;
		_vel.y = 0;
		updater = &Player::IdleUpdate;
		Obj::ChangeAnim(ANIM_TYPE::IDLE);
	}*/
}

