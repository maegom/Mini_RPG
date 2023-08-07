#pragma once

#include "info.h"

class CCharacter
{
public : 
	CCharacter();
	virtual ~CCharacter();

	//캐릭터 공통 정보
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
	//전체 정보 호출 함수
	void SetInfo(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money)
	{
		// 오른쪽 인자의 문자열을 왼쪽 인자에 복사해준다.
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

	//공통 함수들
	//공격력 호출
	virtual int GetAttack()
	{
		return mAttack;
	}
	//방어력 호출
	virtual int GetArmor()
	{
		return mArmor;
	}
	//죽였을 때 획득돈 호출
	int GetMoney()
	{
		return mMoney;
	}
	//죽였을 때 획득 경험치 호출
	int GetExp()
	{
		return mExp;
	}
	//몬스터가 입는 데미지 호출
	bool Damage(int Dmg)
	{
		mHP -= Dmg;

		// 체력이 0보다 작거나 같을 경우(죽었을 경우) true, 아니면  false를 리턴한다.
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

