#include "GameManager.h"

int main()
{
	//���� �Ŵ��� Ŭ�� ����
	CGameManager Mgr;

	//����, ����, �÷��̾� ���� �ʱ�ȭ
	ItemArray	store = {};
	ItemArray	Inventory = {};
	Player	player = {};


	//�ʱ�ȭ 
	Mgr.Init(&store,&Inventory);

	//����
	Mgr.Run(&store, &Inventory);

	Mgr.Destroy(&store, &Inventory);

	return 0;
}