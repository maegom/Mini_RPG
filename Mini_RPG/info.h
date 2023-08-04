#pragma once

#include <iostream>
#include "Array.h"

//아이템 저장공간 제한
#define	ITEMARRAY_MAXCOUNT	10

enum EBattleType
{
	Easy,
	Normal,
	Hard
};

enum EEquipType
{
	Equip_None = -1,
	Equip_Weapon,
	Equip_Armor,
	Equip_End
};
