#pragma once

#include "Info.h"

//�÷��̾� ���� ������
enum class EJob
{
	None,
	Knight,
	Archer,
	Magicion,
	End
};

//�÷��̾� Ŭ����
class CPlayer
{
public:
	CPlayer();
	~CPlayer();

private:
	char	mName[32];
	EJob	mJob;
	int		mAttack;
	int		mArmor;
	int		mHP;
	int		mHPMax;
	int		mMP;
	int		mMPMax;
	int		mLevel;
	int		mExp;
	int		mMoney;
	class CItem* mEquipItem[Equip_End]; //���� ������

	//private ���� ȣ�� �� ���� �Լ�
public:
	
	

	//���ݷ� ȣ��
	int GetAttack();
	//���� ȣ��
	int GetArmor();

	//������ ȣ��
	int GetMoney()
	{
		return mMoney;
	}

	//������ �߻� (hp ����)
	bool Damage(int Dmg)
	{
		mHP -= Dmg;

		// ü���� 0���� �۰ų� ���� ���(�׾��� ���) true, �ƴϸ�  false�� �����Ѵ�.
		return mHP <= 0;
	}

	//����ġ �߰�
	void AddExp(int Exp)
	{
		mExp += Exp;
	}

	//�� �߰�
	void AddMoney(int Money)
	{
		mMoney += Money;
	}

	//���ݷ� ����
	void SetAttack(int Attack)
	{
		mAttack = Attack;
	}

	//��Ȱ 
	void Resurrection()
	{
		//����ġ, �� �г�Ƽ
		mExp = (int)(mExp * 0.9f);
		mMoney = (int)(mMoney * 0.9f);

		//��Ȱ
		mHP = mHPMax;
		mMP = mMPMax;
	}
	//���� ����
	bool Equip(class CItem* ChangeItem,
		class CItem** EquipItem);

public:
	bool Init();
	void Output();
};

