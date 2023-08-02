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
	CItem(const CItem& ref); //복사 생성자
	~CItem();

	//아이템 정보
private:
	char		mName[32];
	EItemType	mType;
	int			mPrice;
	int			mSell;

public:
	//아이템 가격 호출
	int GetPrice()
	{
		return mPrice;
	}

public:
	bool Init(const char* Name, EItemType Type, int Price, int Sell);
	bool Init(FILE* FileStream);
	void Output();
};

