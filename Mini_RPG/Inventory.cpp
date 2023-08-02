#include "Inventory.h"
#include "Item.h"

CInventory* CInventory::mInst = nullptr;

CInventory::CInventory() :
	mItemArray{},
	mCount(0)
{
}

CInventory::~CInventory()
{
	// 인벤토리의 아이템은 하나하나가 모두 동적할당되어 생성된 아이템이므로
	// 인벤토리를 제거할 때 반드시 이 아이템들도 제거를 해주어야 한다.
	for (int i = 0; i < mCount; ++i)
	{
		delete mItemArray[i];
	}
}

int CInventory::Menu()
{
	system("cls");
	for (int i = 0; i < mCount; ++i)
	{
		std::cout << i + 1 << ". ";
		mItemArray[i]->Output();
		std::cout << std::endl;
	}

	std::cout << mCount + 1 << ". 뒤로가기" << std::endl;

	std::cout << "아이템을 선택하세요 : ";
	int	Input;
	std::cin >> Input;

	if (Input <= 0 ||
		Input > mCount + 1)
		return 0;

	return Input;
}

bool CInventory::Init()
{
	return true;
}

void CInventory::Run()
{
	while (true)
	{
		int Input = Menu();

		if (Input == -1)
			continue;

		else if (Input == mCount + 1)
			break;
	}
}
