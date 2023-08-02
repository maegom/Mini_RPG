#pragma once

#include "Info.h"

//전투 메뉴
enum class EBattleMenu
{
	None,
	Attack,
	Back
};

//전투 결과 
enum class EBattleResult
{
	None,
	PlayerDeath,
	MonsterDeath
};

// 전투 클래스
class CBattle
{
public:
	CBattle();
	~CBattle();

private:
	EBattleType	mBattleType;

private:
	//메뉴 함수
	EBattleMenu Menu();
	// 공격 함수
	EBattleResult Attack(class CPlayer* Player, class CMonster* Monster);

public:
	bool Init(EBattleType Type);
	void Run();
};

