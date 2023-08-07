#include "ItemArmor.h"

CItemArmor::CItemArmor()
{
	mType = EItemType::Armor;
}

CItemArmor::CItemArmor(const CItemArmor& ref) :
	CItem(ref)
{
	mType = EItemType::Armor;
}

CItemArmor::~CItemArmor()
{
}

bool CItemArmor::Init()
{
	return true;
}

void CItemArmor::Output()
{
	//CItem::Output();
	std::cout << "이름 : " << mName << "\t종류 : 방어구" << std::endl;
	std::cout << "방어력 : " << mOption << std::endl;

	std::cout << "Price : " << mPrice << "\tSell : "
		<< mSell << std::endl;
}
