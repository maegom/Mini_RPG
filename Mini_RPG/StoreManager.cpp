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
