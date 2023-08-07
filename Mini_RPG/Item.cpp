#include "Item.h"

//아이템 클래스 초기화
CItem::CItem() : 
	mType(EItemType::Weapon),
	mPrice(0),
	mSell(0),
	mOption(0)

{
}

//아이템 복사
CItem::CItem(const CItem& ref)
{
	// this는 새로 생성할 아이템 객체의 주소이다.
	// *this 를 하게 되면 새로 생성한 객체가 된다.
	// 이렇게 해주면 모든 값들을 그대로 복사하게 된다.
	// 얕은복사가 일어난다.
	*this = ref;
}

CItem::~CItem()
{
}

bool CItem::Init(const char* Name, EItemType Type, int Price, int Sell,
	EEquipType EquipType)
{
	return true;
}

//아이템 파일 로드
bool CItem::Init(FILE* FileStream)
{
	//항목별 파일 읽기
	fread(mName, sizeof(char), 32, FileStream); //이름

	fread(&mEquipType, sizeof(EEquipType), 1, FileStream); //장착 종류
	fread(&mOption, sizeof(int), 1, FileStream); //옵션값

	fread(&mPrice, sizeof(int), 1, FileStream); //가격
	fread(&mSell, sizeof(int), 1, FileStream); 

	return true;
}

bool CItem::Init()
{
	return true;
}

//아이템 출력 
void CItem::Output()
{
	std::cout << "이름 : " << mName << "\t종류 : ";

	switch (mType)
	{
	case EItemType::Weapon:
		std::cout << "무기\n";
		std::cout << "공격력 : ";
		break;
	case EItemType::Armor:
		std::cout << "방어구\n";
		std::cout << "방어력 : ";
		break;
	}

	std::cout << mOption << std::endl;

	std::cout << "Price : " << mPrice << "\tSell : "
		<< mSell << std::endl;
}
