#pragma once

#include "Info.h"

//오브젝트 매니저 클래스
class CObjectManager
{
private:
	CObjectManager();
	~CObjectManager();

	//동적할당 및 제거
private:
	static CObjectManager* mInst;

public:
	static CObjectManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CObjectManager;

		return mInst;
	}

	static void DestroyInst()
	{
		if (nullptr != mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}

private:
	// 변수 선언과 함께 전방선언을 해서 포인터 변수를 사용할 수 있다.
	class CPlayer* mPlayer;

public:
	//플레이어 호출
	CPlayer* GetPlayer()
	{
		return mPlayer;
	}
	//몬스터 생성
	class CMonster* CreateMonster(EBattleType Type);

	bool Init();
	
};

