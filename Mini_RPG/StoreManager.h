#pragma once

#include "Info.h"

enum class EStoreMenu
{
	None,
	Weapon,
	Armor,
	Back
};

class CStoreManager
{
private:
	CStoreManager();
	~CStoreManager();

private:
	static CStoreManager* mInst;

public:
	static CStoreManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CStoreManager;

		return mInst;
	}

	static void DestroyInst()
	{
		if (nullptr != mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}

private:
	class CStore* mStore[2];


private:
	EStoreMenu Menu();

public:
	bool Init();
	void Run();
};

