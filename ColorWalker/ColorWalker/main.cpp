#include "DxLib.h"
#include "Scene/SceneMng.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	while (ProcessMessage() == 0 && DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		SceneMng::GetInstance().Run();
	}					// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
