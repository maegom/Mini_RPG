#pragma once

#include "Info.h"

enum class EItemType
{
	Weapon,
	Armor
};

class CItem
{
public:
	CItem();
	CItem(const CItem& ref); //���� ������
	~CItem();

	//������ ����
private:
	char		mName[32];
	EItemType	mType;
	int			mPrice;
	int			mSell;

public:
	//������ ���� ȣ��
	int GetPrice()
	{
		return mPrice;
	}

public:
	bool Init(const char* Name, EItemType Type, int Price, int Sell);
	bool Init(FILE* FileStream);
	void Output();
};

