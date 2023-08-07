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
	CItem(const CItem& ref); //���� ������
	virtual ~CItem();

	//������ ����
protected:
	EItemType	mType;
	EEquipType	mEquipType;
	int			mOption;
	int			mPrice;
	int			mSell;

public:
	//��� �̸� ȣ��
	const char* GetName()
	{
		return mName;
	}

	//��� �ɼ� ȣ��
	int GetOption()
	{
		return mOption;
	}

	//���� ��� ���� ȣ��
	EEquipType GetEquipType()
	{
		return mEquipType;
	}

	//���� ȣ��
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


