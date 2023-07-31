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
	// 메뉴
	EMainMenu Menu();

	//전투 매니저 선언
	CBattleManager* mBattleMgr;
	CStoreManager* mStoreMgr;
};
