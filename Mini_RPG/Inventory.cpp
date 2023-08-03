#include "Inventory.h"
#include "Item.h"
#include "ObjectManager.h"
#include "Player.h"

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

//인벤토리 선택 메뉴
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
		return -1;

	return Input;
}

bool CInventory::Init()
{
	return true;
}

//인벤토리 실행
void CInventory::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	while (true)
	{
		int Input = Menu();

		if (Input == -1)
			continue;

		else if (Input == mCount + 1)
			break;

		int	ItemIndex = Input - 1;

		CItem* ChangeItem = nullptr;

		//아이템 장착
		if (Player->Equip(mItemArray[ItemIndex], &ChangeItem))
		{
			// 이미 장착 아이템이 있을 경우
			if (ChangeItem)
			{
				mItemArray[ItemIndex] = ChangeItem;
			}

			else
			{
				// 장착하고 있던 아이템이 없을 경우 인벤토리의 해당 칸부터
				// 뒤에 있는 모든 아이템을 앞으로 1칸씩 이동시킨다.
				for (int i = ItemIndex; i < mCount - 1; ++i)
				{
					mItemArray[i] = mItemArray[i + 1];
				}

				--mCount;
			}
		}
	}
}
