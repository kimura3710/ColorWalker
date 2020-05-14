#include "Player.h"
#include ""

Player::Player()
{
}

Player::Player(Vector2d pos)
{
	_pos = pos;
	_size = { 64,63 };
	_alive = true;
}

Player::~Player()
{
}

void Player::Update(void)
{
}

void Player::Draw(void)
{
}

void Player::Move(void)
{
}

void Player::Init(void)
{
}
