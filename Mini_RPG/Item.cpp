#include "Item.h"

//아이템 클래스 초기화
CItem::CItem() :
	mName{},
	mType(EItemType::Weapon),
	mPrice(0),
	mSell(0)

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

bool CItem::Init(const char* Name, EItemType Type, int Price, int Sell)
{
	return true;
}

//아이템 파일 로드
bool CItem::Init(FILE* FileStream)
{
	fread(mName, sizeof(char), 32, FileStream);
	fread(&mType, sizeof(EItemType), 1, FileStream);
	fread(&mPrice, sizeof(int), 1, FileStream);
	fread(&mSell, sizeof(int), 1, FileStream);

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
		break;
	case EItemType::Armor:
		std::cout << "방어구\n";
		break;
	}

	std::cout << "Price : " << mPrice << "\tSell : "
		<< mSell << std::endl;
}
