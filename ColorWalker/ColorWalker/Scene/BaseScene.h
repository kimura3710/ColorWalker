#pragma once
#include <memory>

enum class SCN_ID
{
	TITLE,
	SELECT,
	GAME,
	RESULT,
	MAX
};

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};
	virtual unique_Base Update(unique_Base own) = 0;
	virtual SCN_ID GetScnID(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Init(void) = 0;
};
