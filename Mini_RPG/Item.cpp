#include "Item.h"

//������ Ŭ���� �ʱ�ȭ
CItem::CItem() :
	mName{},
	mType(EItemType::Weapon),
	mPrice(0),
	mSell(0)

{
}

//������ ����
CItem::CItem(const CItem& ref)
{
	// this�� ���� ������ ������ ��ü�� �ּ��̴�.
	// *this �� �ϰ� �Ǹ� ���� ������ ��ü�� �ȴ�.
	// �̷��� ���ָ� ��� ������ �״�� �����ϰ� �ȴ�.
	// �������簡 �Ͼ��.
	*this = ref;
}

CItem::~CItem()
{
}

bool CItem::Init(const char* Name, EItemType Type, int Price, int Sell)
{
	return true;
}

//������ ���� �ε�
bool CItem::Init(FILE* FileStream)
{
	fread(mName, sizeof(char), 32, FileStream);
	fread(&mType, sizeof(EItemType), 1, FileStream);
	fread(&mPrice, sizeof(int), 1, FileStream);
	fread(&mSell, sizeof(int), 1, FileStream);

	return true;
}

//������ ��� 
void CItem::Output()
{
	std::cout << "�̸� : " << mName << "\t���� : ";

	switch (mType)
	{
	case EItemType::Weapon:
		std::cout << "����\n";
		break;
	case EItemType::Armor:
		std::cout << "��\n";
		break;
	}

	std::cout << "Price : " << mPrice << "\tSell : "
		<< mSell << std::endl;
}