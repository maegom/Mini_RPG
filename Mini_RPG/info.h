#pragma once

#include <iostream>

//아이템 종류
enum class EItemType
{
	Weapon,
	Armor
};

//장착아이템 
enum EItemEquip
{
	Equip_Weapon,
	Equip_Armor,
	Equip_End
};

//아이템 정보
struct Item
{
	char	Name[32];
	EItemType	Type;
	int		Price;
	int		Sell;
};

//저장공간 
#define	ITEMARRAY_MAXCOUNT	10

//아이템 + 개수
struct ItemArray
{
	Item* ItemList[ITEMARRAY_MAXCOUNT];
	int		Count;
};

//플레이어 정보
struct Player
{
	char	Name[32];
	int		Attack;
	int		Armor;
	int		HP;
	int		HPMax;
	int		MP;
	int		MPMax;
	int		Level;
	int		Exp;
	int		Money;
	Item* EquipItem[Equip_End];
};

//아이템 출력
int OutputItemList(const ItemArray* Array);
