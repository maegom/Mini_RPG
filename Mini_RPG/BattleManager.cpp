#include "BattleManager.h"
// 실제 Battle 클래스를 사용해야 하기 때문에 include를 해준다.
#include "Battle.h"

//전투 매니저 초기화
CBattleManager* CBattleManager::mInst = nullptr;

CBattleManager::CBattleManager() :
	mBattle{}
{
}

CBattleManager::~CBattleManager()
{
}

//전투 등급 메뉴
EBattleLevelMenu CBattleManager::Menu()
{
	system("cls");
	std::cout << "1. 쉬움" << std::endl;
	std::cout << "2. 보통" << std::endl;
	std::cout << "3. 어려움" << std::endl;
	std::cout << "4. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EBattleLevelMenu::None ||
		Input > (int)EBattleLevelMenu::Back)
		return EBattleLevelMenu::None;

	return (EBattleLevelMenu)Input;
}

// 전투 등급에 따른 분류
bool CBattleManager::Init()
{
	// 전투 3개를 모두 생성해둔다.
	for (int i = 0; i < 3; ++i)
	{
		mBattle[i] = new CBattle;

		mBattle[i]->Init((EBattleType)i);
	}

	return true;
}

//메뉴 선택에 따른 실행
void CBattleManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EBattleLevelMenu::Easy:
			mBattle[0]->Run();
			break;
		case EBattleLevelMenu::Normal:
			mBattle[1]->Run();
			break;
		case EBattleLevelMenu::Hard:
			mBattle[2]->Run();
			break;
		case EBattleLevelMenu::Back:
			return;
		}
	}
}
