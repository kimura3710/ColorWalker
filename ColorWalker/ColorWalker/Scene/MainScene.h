#pragma once
#include "BaseScene.h"
#include "../Obj/Obj.h"
#include "../Obj/Block/Block.h"
#include <vector>
class Player;
class Block;


class MainScene :
	public BaseScene
{
public:
	MainScene();
	~MainScene();
	unique_Base Update(unique_Base own)override final;
	void Init(void);
	SCN_ID GetScnID(void);
private:
	std::vector<sharedObj> _objList;
	Player *pl;
	Block *bl;
	int _ghGameScreen;
	void Draw(void);

	void HitCheck(ActRect & ra, ActRect & rb, Block & block);)

};

