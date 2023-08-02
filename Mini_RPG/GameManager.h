#pragma once

#include "Info.h"

//메인 메뉴
enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

//게임 매니저 클래스
class CGameManager
{
private:
	CGameManager();
	~CGameManager();

	//동적할당 및 제거
private:
	static CGameManager* mInst;

public:
	static CGameManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CGameManager;

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
//메뉴 출력 함수
private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};

