#pragma once

#include "Info.h"

class CInventory
{
private:
	CInventory();
	~CInventory();

private:
	static CInventory* mInst;

public:
	static CInventory* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CInventory;

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
	class CItem* mItemArray[ITEMARRAY_MAXCOUNT];
	int		mCount;

public:
	bool IsFull()
	{
		return mCount == ITEMARRAY_MAXCOUNT;
	}

public:
	void AddItem(class CItem* Item)
	{
		mItemArray[mCount] = Item;
		++mCount;
	}

public:
	int Menu();

public:
	bool Init();
	void Run();
};

