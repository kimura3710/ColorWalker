#pragma once
#include "Obj.h"

class Player : public Obj
{
public:
	Player();
	Player(Vector2d pos);
	~Player();
	void Update(void) override;
	void Draw(void) override;

	void Move(void);
private:
	void Init(void);
};