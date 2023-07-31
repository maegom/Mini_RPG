#include "StoreManager.h"

CStoreManager::CStoreManager()
{
}

CStoreManager::~CStoreManager()
{
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


bool CStoreManager::Init()
{
    return true;
}

void CStoreManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EStoreMenu::None:
			break;
		case EStoreMenu::Buy:
			break;
		case EStoreMenu::Sell:
			break;
		case EStoreMenu::Back:
			return;
		}
	}
}
