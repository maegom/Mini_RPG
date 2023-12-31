#pragma once

#include "Object.h"

enum class EItemType
{
	Weapon,
	Armor
};

class CItem :
	public CObject
{
public:
	CItem();
	CItem(const CItem& ref); //복사 생성자
	virtual ~CItem();

	//아이템 정보
protected:
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
	virtual bool Init(FILE* FileStream);
	virtual bool Init();
	virtual void Output();
};


