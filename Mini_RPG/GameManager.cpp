#include "GameManager.h" 

//객체 생성시 호출
CGameManager::CGameManager() :
	mBattleMgr(nullptr),  //초기화 
	mStoreMgr(nullptr) 
{
	
}

//객체 제거시 호출
CGameManager::~CGameManager() 
{
	if (mBattleMgr)
	{
		//동적할당 제거 및 초기화
		delete 	mBattleMgr;
		mBattleMgr = nullptr;

	}

	if (mStoreMgr)
	{
		//동적할당 제거 및 초기화
		delete 	mStoreMgr;
		mStoreMgr = nullptr;

	}
	
}

//첫 메뉴 출력
EMainMenu CGameManager::Menu()
{
	system("cls");
	std::cout << "1. 전투" << std::endl;
	std::cout << "2. 상점" << std::endl;
	std::cout << "3. 가방" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";

	// 선택값 입력
	int Input;
	std::cin >> Input;

	//입력 오류 예외처리
	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	//입력시 입력값 반환
	return (EMainMenu)Input;
}

//초기화
bool CGameManager::Init()
{
	// 전투 관리자 클래스 생성과 초기화
	mBattleMgr = new CBattleManager;
	mStoreMgr = new CStoreManager;

	if (!mBattleMgr->Init())
		return false;
	if (!mStoreMgr->Init())
		return false;

	return true;
}

//실행
void CGameManager::Run()
{
	while (true)
	{
		//첫 메뉴 입력값에 따른 분기
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