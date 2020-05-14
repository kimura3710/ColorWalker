#pragma once
#include <memory>
#include <vector>
#include "../common/ImageMng.h"

struct GameScreen
{
	Vector2 lt = { 150,105 };
	Vector2 rt = { 150,105 };
	Vector2 lb = { 150,105 };
	Vector2 rb = { 150,105 };
};

enum class ANIM_TYPE
{
	NORMAL,
	MAX
};

enum class OBJ_TYPE
{
	CHARCTOR,
	MAP,
	MAX
};

enum class COLOR_TYPE
{
	WHITE,
	RED,
	BLUE,
	YELLOW
};

using AnimVector = std::vector<std::pair<int,int>>;


class Obj
{
public:
	Obj();
	virtual~Obj();

	virtual void Update(void) = 0;
	virtual void Draw(void) = 0 ;

	bool IsAlive(void) { return _alive; }

	bool OutOfScreen(void);
	void SetAnimCnt(void);

	int GetLastAnim(void);

	COLOR_TYPE GetColor(void);
protected:
	bool SetAnim(const ANIM_TYPE & key, AnimVector & data);

	Vector2d _pos;
	Vector2d _size;
	bool _alive;

	COLOR_TYPE colorType;
private:
	std::map<ANIM_TYPE, AnimVector> _animMap;
	ANIM_TYPE _animKey;
	int _animCnt;
};