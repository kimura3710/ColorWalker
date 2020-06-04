#include "Block.h"

Block::Block()
{
}

Block::Block(Vector2d pos)
{
	_pos = pos;
	_size = { 64,64 };
	_alive = true;
	_turnFlag = true;
	Init();
}


Block::~Block()
{
}

void Block::Update(void)
{
}

void Block::Draw(void)
{
}

OBJ_TYPE Block::GetObjType(void)
{
	return OBJ_TYPE::TILE;
}

void Block::Init(void)
{
	AnimVector data;
	data.emplace_back(IMAGE_ID("block")[0], 1);
	Obj::SetAnim(ANIM_TYPE::IDLE, data);
}
