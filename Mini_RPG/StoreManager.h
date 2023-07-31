#pragma once
#include "Store.h"

enum class EStoreMenu
{
	None,
	Buy,
	Sell,
	Back

};

class CStoreManager
{
public :
	CStoreManager();
	~CStoreManager();

private:
	EStoreMenu Menu();

	CStore* mStore;


public:
	bool Init(ItemArray* store);
	void Run(ItemArray* store);

};

