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
	bool Init(FILE* FileStream);
	void Output();
};


