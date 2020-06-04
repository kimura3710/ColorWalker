#pragma once
#include <memory>
#include "Obj.h"
class InputState;

class Player : public Obj
{
public:
	Player();
	Player(Vector2d pos);
	~Player();
	void Update(void) override;
	void Draw(void) override;
	OBJ_TYPE GetObjType(void);

	void Landing(void);
private:
	bool Init(void);
	std::unique_ptr<InputState> input;

	void IdleUpdate(void);
	void WalkUpdate(void);
	void JumpUpdate(void);
	void (Player::*_updater)();

	

	
};