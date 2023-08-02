#pragma once

#include "Info.h"

//���� Ŭ����
class CMonster
{
public:
	CMonster();
	~CMonster();

	//���� ����
private:
	char	mName[32];
	int		mAttack;
	int		mArmor;
	int		mHP;
	int		mHPMax;
	int		mMP;
	int		mMPMax;
	int		mLevel;
	int		mExp;
	int		mMoney;

	//���� ���� ȣ�� �� ���� �Լ�
public:
	//���ݷ� ȣ��
	int GetAttack()
	{
		return mAttack;
	}
	//���� ȣ��
	int GetArmor()
	{
		return mArmor;
	}
	//�׿��� �� ȹ�海 ȣ��
	int GetMoney()
	{
		return mMoney;
	}
	//�׿��� �� ȹ�� ����ġ ȣ��
	int GetExp()
	{
		return mExp;
	}
	//���Ͱ� �Դ� ������ ȣ��
	bool Damage(int Dmg)
	{
		mHP -= Dmg;

		// ü���� 0���� �۰ų� ���� ���(�׾��� ���) true, �ƴϸ�  false�� �����Ѵ�.
		return mHP <= 0;
	}

public:
	// "aaa" �̷� ���ڿ��� ���޹��� ��� const char* Ÿ���� ����Ѵ�.
	bool Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money);
	void Output();
};
