#pragma once
#include <memory>
#include <vector>
#include "../common/Geometry.h"
#include "../common/ImageMng.h"

class Obj;
using sharedObj = std::shared_ptr<Obj>;

struct GameScreen
{
	Vector2 lt = { 150,105 };
	Vector2 rt = { 150,105 };
	Vector2 lb = { 150,105 };
	Vector2 rb = { 150,105 };
};

enum class ANIM_TYPE
{
	IDLE,
	RUN,
	JUMP,
	NORMAL,
	MAX
};

enum class OBJ_TYPE
{
	PLAYER,
	TILE,
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
	virtual void Draw(void) ;
	virtual OBJ_TYPE GetObjType(void) = 0;

	bool IsAlive(void) { return _alive; }

	bool OutOfScreen(void);

	void CheckGameScreen(Vector2d& pos);
	void SetAnimCnt(void);

	int GetLastAnim(void);

	bool ChangeAnim(const ANIM_TYPE animKey);

	bool HitCheck(const std::vector<sharedObj> & _objList);

	const Vector2d GetPos(void) const;
	const Vector2 GetSize(void) const;
	

	COLOR_TYPE GetColor(void);
protected:
	Rect rect;
	bool SetAnim(const ANIM_TYPE & key, AnimVector & data);

	Vector2d _pos;
	Vector2d _vel;
	Vector2 _size;

	bool _isAir;

	double _angle;

	bool _turnFlag; /// trueÇ≈í èÌï`âÊfalseÇ≈îΩì]ï`âÊÅiXé≤Åj
	bool _alive;

	COLOR_TYPE colorType;
private:
	std::map<ANIM_TYPE, AnimVector> _animMap;
	ANIM_TYPE _animKey;
	int _animCnt;
	unsigned int _animID;

	int up;
	int down;
	int right;
	int left;
};