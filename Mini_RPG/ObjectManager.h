#pragma once

#include "Info.h"

//������Ʈ �Ŵ��� Ŭ����
class CObjectManager
{
private:
	CObjectManager();
	~CObjectManager();

	//�����Ҵ� �� ����
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
	// ���� ����� �Բ� ���漱���� �ؼ� ������ ������ ����� �� �ִ�.
	class CPlayer* mPlayer;

public:
	//�÷��̾� ȣ��
	CPlayer* GetPlayer()
	{
		return mPlayer;
	}
	//���� ����
	class CMonster* CreateMonster(EBattleType Type);

	bool Init();
	
};

