#pragma once

#include "Info.h"

//전투 레벨 설정 메뉴
enum class EBattleLevelMenu
{
	None,
	Easy,
	Normal,
	Hard,
	Back
};

//전투 클래스 전방선언
class CBattle;

//전투 매니저 클래스
class CBattleManager
{
private:
	CBattleManager();
	~CBattleManager();

	//동적할당 및 제거
private:
	static CBattleManager* mInst;

public:
	static CBattleManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CBattleManager;

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
	//전투 등급 
private:
	CBattle* mBattle[3];

private:
	EBattleLevelMenu Menu();

public:
	bool Init();
	void Run();
};

