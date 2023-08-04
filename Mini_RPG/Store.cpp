#include "Store.h"
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
#include "ObjectManager.h"

CStore::CStore() 
{
}

CStore::~CStore()
{
}
//상점안 구매 입력
int CStore::Menu()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	system("cls");
	for (int i = 0; i < mItemArray.size(); ++i)
	{
		std::cout << i + 1 << ". ";
		mItemArray[i]->Output();
		std::cout << std::endl;
	}

	std::cout << mItemArray.size() + 1 << ". 뒤로가기" << std::endl;

	std::cout << "보유금액 : " << Player->GetMoney() << std::endl;

	std::cout << "아이템을 선택하세요 : ";
	int	Input;
	std::cin >> Input;

	if (Input <= 0 ||
		Input > mItemArray.size() + 1)
		return 0;

	return Input;
}


bool CStore::Init(const char* FileName)
{//파일 입력 받을 초기화
	FILE* FileStream = nullptr;

	//파일 입력
	fopen_s(&FileStream, FileName, "rb");

	if (!FileStream)
		return false;

	int Count = 0;
	fread(&Count, sizeof(int), 1, FileStream); //아이템 개수 입력
	// 위에서 읽어온 아이템의 수량만큼 동적배열로 할당해준다.
	 

	//아이템 개수만큼 아이템 정보 입력
	for (int i = 0; i < Count; ++i)
	{
		CItem* Item = new CItem;

		Item->Init(FileStream);

		mItemArray.push_back(Item);
	}

	fclose(FileStream);

	return true;
}

//상점 실행 
void CStore::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	while (true) 
	{
		int Input = Menu();

		if (Input == -1)
			continue;

		else if (Input == mItemArray.size() + 1)
			break;

		int	ItemIndex = Input - 1;

		// 인벤토리에 칸이 부족할 경우 추가할 수 없다.
		if (CInventory::GetInst()->IsFull())
		{
			std::cout << "가방의 공간이 부족합니다." << std::endl;
			system("pause");
			continue;
		}

		// 가지고 있는 돈보다 작은지 판단한다.
		else if (Player->GetMoney() < mItemArray[ItemIndex]->GetPrice())
		{
			std::cout << "소지금이 부족합니다." << std::endl;
			system("pause");
			continue;
		}

		// 인벤토리에 아이템을 추가해준다.
		// 구매할 아이템을 복사생성자의 인자에 전달해주어서 인벤토리에 추가하기 위해
		// 새로 생성하는 아이템의 정보를 구매한 아이템의 정보로 그대로 복사해준다.
		CItem* InvenItem = new CItem(*mItemArray[ItemIndex]);

		// 인벤토리에 아이템을 추가해준다.
		CInventory::GetInst()->AddItem(InvenItem);

		Player->AddMoney(-InvenItem->GetPrice());
	}
}
