#include "GameManager.h"
#include "BattleManager.h"
#include "ObjectManager.h" 
#include "StoreManager.h" 
#include "Inventory.h"

CGameManager* CGameManager::mInst = nullptr; 

//��ü ������ ȣ��
CGameManager::CGameManager() 
{	
}

//��ü ���Ž� ȣ��
CGameManager::~CGameManager() 
{
	CObjectManager::DestroyInst();
	CBattleManager::DestroyInst();
	CStoreManager::DestroyInst();
}

//ù �޴� ���
EMainMenu CGameManager::Menu()
{
	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. ����" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";

	// ���ð� �Է�
	int Input;
	std::cin >> Input;

	//�Է� ���� ����ó��
	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	//�Է½� �Է°� ��ȯ
	return (EMainMenu)Input;
}



//�ʱ�ȭ
bool CGameManager::Init()
{
	// ������Ʈ ������ �ʱ�ȭ
	if (!CObjectManager::GetInst()->Init())
		return false;

	// ���� ������ Ŭ���� ������ �ʱ�ȭ
	if (!CBattleManager::GetInst()->Init())
		return false;

	//���� ������ Ŭ���� ������ �ʱ�ȭ 
	if (!CStoreManager::GetInst()->Init())
		return false;
	// �κ��丮 �ʱ�ȭ
	if (!CInventory::GetInst()->Init())
		return false;

 
	return true;
}

//����
void CGameManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EMainMenu::Battle:
			CBattleManager::GetInst()->Run();
			break;
		case EMainMenu::Store:
			CStoreManager::GetInst()->Run();
			break;
		case EMainMenu::Inventory:
			CInventory::GetInst()->Run();
			break;
		case EMainMenu::Exit:
			return;
		}
	}
}
