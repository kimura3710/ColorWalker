#pragma once
#include "Obj.h"

class Player : public Obj
{
public:
	Player();
	~Player();
	void Update(void) override;
	void Draw(void) override;
};