#pragma once

#include "Info.h"

//���� �޴�
enum class EBattleMenu
{
	None,
	Attack,
	Back
};

//���� ��� 
enum class EBattleResult
{
	None,
	PlayerDeath,
	MonsterDeath
};

// ���� Ŭ����
class CBattle
{
public:
	CBattle();
	~CBattle();

private:
	EBattleType	mBattleType;

private:
	//�޴� �Լ�
	EBattleMenu Menu();
	// ���� �Լ�
	EBattleResult Attack(class CPlayer* Player, class CMonster* Monster);

public:
	bool Init(EBattleType Type);
	void Run();
};

