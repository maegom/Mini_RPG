#include "GameManager.h"

int main()
{
	//게임 매니저 클라스 생성
	CGameManager Mgr;

	//초기화 
	Mgr.Init();

	//실행
	Mgr.Run();

	return 0;
}