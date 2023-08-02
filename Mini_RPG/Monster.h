#pragma once

#include "Info.h"

//몬스터 클래스
class CMonster
{
public:
	CMonster();
	~CMonster();

	//몬스터 정보
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

	//몬스터 정보 호출 및 수정 함수
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

public:
	// "aaa" 이런 문자열을 전달받을 경우 const char* 타입을 사용한다.
	bool Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money);
	void Output();
};
