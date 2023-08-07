#pragma once

#include "info.h"

class CCharacter
{
public : 
	CCharacter();
	virtual ~CCharacter();

	//ĳ���� ���� ����
protected:
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

	
public:
	//��ü ���� ȣ�� �Լ�
	void SetInfo(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money)
	{
		// ������ ������ ���ڿ��� ���� ���ڿ� �������ش�.
		strcpy_s(mName, Name);
		mAttack = Attack;
		mArmor = Armor;
		mHP = HP;
		mHPMax = HP;
		mMP = MP;
		mMPMax = MP;
		mLevel = Level;
		mExp = Exp;
		mMoney = Money;
	}

	//���� �Լ���
	//���ݷ� ȣ��
	virtual int GetAttack()
	{
		return mAttack;
	}
	//���� ȣ��
	virtual int GetArmor()
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

	void AddExp(int Exp)
	{
		mExp += Exp;
	}

	void AddMoney(int Money)
	{
		mMoney += Money;
	}

	void SetAttack(int Attack)
	{
		mAttack = Attack;
	}

	void Resurrection()
	{
		mExp = (int)(mExp * 0.9f);
		mMoney = (int)(mMoney * 0.9f);

		mHP = mHPMax;
		mMP = mMPMax;
	}

public: 
	virtual bool Init();
	virtual void Output();
};

