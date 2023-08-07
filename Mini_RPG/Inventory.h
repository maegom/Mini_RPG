#pragma once

#include "Info.h"

//�κ��丮 Ŭ����
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
	//�κ��丮 ������ ���� ����
	class CItem* mItemArray[ITEMARRAY_MAXCOUNT];
	int		mCount; //������ ���� ����

	//�κ��丮 á����
public:
	bool IsFull()
	{
		return mCount == ITEMARRAY_MAXCOUNT;
	}

	//�κ��丮�� ������ �߰�
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