#include "GameManager.h" 

//��ü ������ ȣ��
CGameManager::CGameManager() :
	mBattleMgr(nullptr),  //�ʱ�ȭ 
	mStoreMgr(nullptr),
	mInventory(nullptr)

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
	if (mInventory)
	{
		//�����Ҵ� ���� �� �ʱ�ȭ
		delete 	mInventory;
		mInventory = nullptr;

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
bool CGameManager::Init(ItemArray* store, ItemArray* Inventory)
{
	// ���� ������ Ŭ���� ������ �ʱ�ȭ
	mBattleMgr = new CBattleManager;
	mStoreMgr = new CStoreManager;
	mInventory = new CInventoryManager;

	if (!mBattleMgr->Init())
		return false;
	if (!mStoreMgr->Init(store))
		return false;

	if (!mInventory->Init(Inventory))
		return false;

	return true;
}

//����
void CGameManager::Run(ItemArray* store, ItemArray* Inventory)
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
			mStoreMgr->Run(store);
			break;
		case EMainMenu::Inventory:
			mInventory->Run(Inventory);
			break;
		case EMainMenu::Exit:
			return;
	
		}

	}
}

void CGameManager::Destroy(ItemArray* store, ItemArray* Inventory)
{
	for (int i = 0; i < store->Count; ++i)
	{
		delete store->ItemList[i];
	}

	for (int i = 0; i < store->Count; ++i)
	{
		delete Inventory->ItemList[i];
	}
}
