#pragma once

#include "Info.h"

//플레이어 직업 열거형
enum class EJob
{
	None,
	Knight,
	Archer,
	Magicion,
	End
};

//플레이어 클래스
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

	//private 변수 호출 및 수정 함수
public:
	//공격력 호출
	int GetAttack()
	{
		return mAttack;
	}
	//방어력 호출
	int GetArmor()
	{
		return mArmor;
	}
	//소지금 호출
	int GetMoney()
	{
		return mMoney;
	}

	//데미지 발생 (hp 변동)
	bool Damage(int Dmg)
	{
		mHP -= Dmg;

		// 체력이 0보다 작거나 같을 경우(죽었을 경우) true, 아니면  false를 리턴한다.
		return mHP <= 0;
	}

	//경험치 추가
	void AddExp(int Exp)
	{
		mExp += Exp;
	}

	//돈 추가
	void AddMoney(int Money)
	{
		mMoney += Money;
	}

	//공격력 수정
	void SetAttack(int Attack)
	{
		mAttack = Attack;
	}

	//부활 
	void Resurrection()
	{
		//경험치, 돈 패널티
		mExp = (int)(mExp * 0.9f);
		mMoney = (int)(mMoney * 0.9f);

		//부활
		mHP = mHPMax;
		mMP = mMPMax;
	}

public:
	bool Init();
	void Output();
};

