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
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �ȱ�" << std::endl;
	std::cout << "3. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
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
