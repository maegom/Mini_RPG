#pragma once

#include "Info.h"

//인벤토리 클래스
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
	//인벤토리 아이템 저장 공간
	class CItem* mItemArray[ITEMARRAY_MAXCOUNT];
	int		mCount; //아이템 저장 개수

	//인벤토리 찼을때
public:
	bool IsFull()
	{
		return mCount == ITEMARRAY_MAXCOUNT;
	}

	//인벤토리에 아이템 추가
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