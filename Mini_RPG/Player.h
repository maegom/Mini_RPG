#pragma once

#include "Character.h"

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
class CPlayer : 
	public CCharacter
{
public:
	CPlayer();
	~CPlayer();

private:
	EJob	mJob;
	class CItem* mEquipItem[Equip_End]; //장착 아이템

public:
	int GetAttack()	override;
	int GetArmor()	override;

	//장착 여부
	bool Equip(class CItem* ChangeItem,
		class CItem** EquipItem);

public:
	bool Init()	override;
	void Output()	override;
};

