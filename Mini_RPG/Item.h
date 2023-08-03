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
	EEquipType	mEquipType;
	int			mOption;
	int			mPrice;
	int			mSell;

public:
	//장비 이름 호출
	const char* GetName()
	{
		return mName;
	}

	//장비 옵션 호출
	int GetOption()
	{
		return mOption;
	}

	//장착 장비 종류 호출
	EEquipType GetEquipType()
	{
		return mEquipType;
	}

	//가격 호출
	int GetPrice()
	{
		return mPrice;
	}

public:
	bool Init(const char* Name, EItemType Type, int Price, int Sell,
		EEquipType EquipType = Equip_None);
	bool Init(FILE* FileStream);
	void Output();
};


