#include "GameManager.h"

int main()
{
	//게임 매니저 클라스 생성
	CGameManager Mgr;

	//상점, 가방, 플레이어 공간 초기화
	ItemArray	store = {};
	ItemArray	Inventory = {};
	Player	player = {};


	//초기화 
	Mgr.Init(&store,&Inventory);

	//실행
	Mgr.Run(&store, &Inventory);

	Mgr.Destroy(&store, &Inventory);

	return 0;
}