#include "ItemWeapon.h"

CItemWeapon::CItemWeapon()
{
	mType = EItemType::Weapon;
}

CItemWeapon::CItemWeapon(const CItemWeapon& ref) :
	CItem(ref)
{
	mType = EItemType::Weapon;
}

CItemWeapon::~CItemWeapon()
{
}

bool CItemWeapon::Init()
{
	return true;
}

void CItemWeapon::Output()
{
	std::cout << "이름 : " << mName << "\t종류 : 무기" << std::endl;
	std::cout << "공격력 : " << mOption << std::endl;

	std::cout << "Price : " << mPrice << "\tSell : "
		<< mSell << std::endl;
}
