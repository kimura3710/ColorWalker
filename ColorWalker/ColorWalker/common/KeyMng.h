#pragma once
#define lpKeyMng KeyMng::GetInstance()

class KeyMng
{
public:
	static KeyMng & GetInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new KeyMng();
		}
		return (*s_Instance);
	}
private:
	int GetNowKey(int keyId);
	int GetOldKey(int keyId);

	bool IsPressing(int keyId)const;
	bool IsTringger(int keyId)const;

	KeyMng();
	KeyMng(const KeyMng&);
	void operator=(const KeyMng&);
	~KeyMng();
	static KeyMng * s_Instance;

	void KeyUpdate(void);

	//int allKey[256];

	int keyState;
	int oldKeyState;
	int nowKey[256];
	int oldKey[256];
};