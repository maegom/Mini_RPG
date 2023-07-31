#pragma once
#include "info.h"

class CInventoryManager
{
public:
	CInventoryManager();
	~CInventoryManager();

	bool Init(ItemArray* Inventory);
	void Run(ItemArray* Inventory);

private :


};

