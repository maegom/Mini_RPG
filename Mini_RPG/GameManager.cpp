#include "GameManager.h"
#include "BattleManager.h"
#include "ObjectManager.h" 
#include "StoreManager.h" 
#include "Inventory.h"

CGameManager* CGameManager::mInst = nullptr; 

//객체 생성시 호출
CGameManager::CGameManager() 
{	
}

//객체 제거시 호출
CGameManager::~CGameManager() 
{
	CObjectManager::DestroyInst();
	CBattleManager::DestroyInst();
	CStoreManager::DestroyInst();
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
	// 오브젝트 관리자 초기화
	if (!CObjectManager::GetInst()->Init())
		return false;

	// 전투 관리자 클래스 생성과 초기화
	if (!CBattleManager::GetInst()->Init())
		return false;

	//상점 관리가 클래스 생성과 초기화 
	if (!CStoreManager::GetInst()->Init())
		return false;
	// 인벤토리 초기화
	if (!CInventory::GetInst()->Init())
		return false;

 
	return true;
}

//실행
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
