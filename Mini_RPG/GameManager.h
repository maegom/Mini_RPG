#pragma once

#include "Info.h"

//���� �޴�
enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

//���� �Ŵ��� Ŭ����
class CGameManager
{
private:
	CGameManager();
	~CGameManager();

	//�����Ҵ� �� ����
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
//�޴� ��� �Լ�
private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};

