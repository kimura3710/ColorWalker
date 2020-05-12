#include "DxLib.h"
#include "Scene/SceneMng.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	while (ProcessMessage() == 0 && DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		SceneMng::GetInstance().Run();
	}					// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
