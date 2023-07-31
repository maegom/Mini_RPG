#pragma once
#include "info.h"

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

public:
	bool Init();
	void Run();
};

