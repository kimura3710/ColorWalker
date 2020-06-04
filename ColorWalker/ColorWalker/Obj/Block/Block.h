#pragma once
#include "../Obj.h"

class Block
	:	public Obj
{
public:
	Block();
	Block(Vector2d pos);
	~Block();
	void Update(void)override;
	void Draw(void)override;
	OBJ_TYPE GetObjType(void)override;
private:
	void Init(void);
};