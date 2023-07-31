#pragma once

#include "BattleManager.h"
#include "StoreManager.h"

enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

class CGameManager
{
public:
	CGameManager();
	~CGameManager();

	bool Init();
	void Run();

private:
	// �޴�
	EMainMenu Menu();

	//���� �Ŵ��� ����
	CBattleManager* mBattleMgr;
	CStoreManager* mStoreMgr;
};
