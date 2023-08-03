#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

//오브젝트 매니저 클래스 초기화
CObjectManager* CObjectManager::mInst = nullptr;

CObjectManager::CObjectManager() :
	mPlayer(nullptr)
{
}

//플레이어 동적할당 제거
CObjectManager::~CObjectManager()
{
	if (mPlayer)
	{
		delete mPlayer;
		mPlayer = nullptr;
	}
}

//플레이어 동적할당
bool CObjectManager::Init()
{
	mPlayer = new CPlayer;

	if (!mPlayer->Init())
		return false;

	return true;
}

//몬스터 생성 함수
CMonster* CObjectManager::CreateMonster(EBattleType Type)
{
	CMonster* Monster = new CMonster;

	switch (Type)
	{
	case Easy:
		Monster->Init("고블린", 25, 10, 100, 10, 1, 1000, 1000);
		break;
	case Normal:
		Monster->Init("오크", 80, 50, 900, 100, 5, 8000, 8000);
		break;
	case Hard:
		Monster->Init("오우거", 200, 150, 2000, 1000, 10, 15000, 15000);
		break;
	}

	return Monster;
}
