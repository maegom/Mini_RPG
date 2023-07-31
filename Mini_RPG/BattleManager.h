#pragma once

#include "info.h"

//���� �޴�
enum class EBattleMenu
{
	None,
	Easy,
	Normal,
	Hard,
	Back
};

class CBattleManager
{
public :
	CBattleManager();
	~CBattleManager();

	bool Init();
	void Run();

private : 
	EBattleMenu Menu();

};

