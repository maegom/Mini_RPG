#include "BattleManager.h"

CBattleManager::CBattleManager()
{
}

CBattleManager::~CBattleManager()
{
}

bool CBattleManager::Init()
{
	return true;
}

EBattleMenu CBattleManager::Menu()
{
	system("cls");
	std::cout << "1. 쉬움" << std::endl;
	std::cout << "2. 보통" << std::endl;
	std::cout << "3. 어려움" << std::endl;
	std::cout << "4. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";

	// 선택값 입력
	int Input;
	std::cin >> Input;

	//입력 오류 예외처리
	if (Input <= (int)EBattleMenu::None || Input > (int)EBattleMenu::Back)
		return EBattleMenu::None;

	//입력시 입력값 반환
	return (EBattleMenu)Input;
}

//실행
void CBattleManager::Run()
{
	while (true)
	{
		switch (Menu())
		{

		case EBattleMenu::Easy:
			break;
		case EBattleMenu::Normal:
			break;
		case EBattleMenu::Hard:
			break;
		case EBattleMenu::Back:
			return;
		}
	}
}

