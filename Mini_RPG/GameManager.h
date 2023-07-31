#pragma once

#include "BattleManager.h"
#include "StoreManager.h"
#include "InventoryManager.h"

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

	bool Init(ItemArray* store, ItemArray* Inventory);
	void Run(ItemArray* store, ItemArray* Inventory);
	void Destroy(ItemArray* store, ItemArray* Inventory);

private:
	// 메뉴
	EMainMenu Menu();

	//전투 매니저 선언
	CBattleManager* mBattleMgr;

	CStoreManager* mStoreMgr;
	CInventoryManager* mInventory;
};
