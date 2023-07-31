#include "GameManager.h" 

//��ü ������ ȣ��
CGameManager::CGameManager() :
	mBattleMgr(nullptr),  //�ʱ�ȭ 
	mStoreMgr(nullptr) 
{
	
}

//��ü ���Ž� ȣ��
CGameManager::~CGameManager() 
{
	if (mBattleMgr)
	{
		//�����Ҵ� ���� �� �ʱ�ȭ
		delete 	mBattleMgr;
		mBattleMgr = nullptr;

	}

	if (mStoreMgr)
	{
		//�����Ҵ� ���� �� �ʱ�ȭ
		delete 	mStoreMgr;
		mStoreMgr = nullptr;

	}
	
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
	// ���� ������ Ŭ���� ������ �ʱ�ȭ
	mBattleMgr = new CBattleManager;
	mStoreMgr = new CStoreManager;

	if (!mBattleMgr->Init())
		return false;
	if (!mStoreMgr->Init())
		return false;

	return true;
}

//����
void CGameManager::Run()
{
	while (true)
	{
		//ù �޴� �Է°��� ���� �б�
		switch (Menu())
		{
		case EMainMenu::Battle:
			mBattleMgr-> Run();
			break;
		case EMainMenu::Store:
			mStoreMgr->Run();
			break;
		case EMainMenu::Inventory:
			break;
		case EMainMenu::Exit:
			return;
	
		}

	}
}