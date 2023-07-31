#include "StoreManager.h"

CStoreManager::CStoreManager() :
	mStore(nullptr)
{
}

CStoreManager::~CStoreManager()
{
	if (mStore)
	{
		delete mStore;
		mStore = nullptr;
	}
}

EStoreMenu CStoreManager::Menu()
{
	system("cls");
	std::cout << "1. 구매" << std::endl;
	std::cout << "2. 팔기" << std::endl;
	std::cout << "3. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EStoreMenu::None ||
		Input > (int)EStoreMenu::Back)
		return EStoreMenu::None;

	return (EStoreMenu)Input;
}


bool CStoreManager::Init(ItemArray* store)
{
	mStore = new CStore;

	if (!mStore->Init(store))
		return false;

    return true;
}

void CStoreManager::Run(ItemArray* store)
{
	while (true)
	{
		switch (Menu())
		{
		case EStoreMenu::Buy:
			mStore->Run(store);
			break;
		case EStoreMenu::Sell:
			break;
		case EStoreMenu::Back:
			return;
		}
	}
}
