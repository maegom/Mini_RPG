#pragma once

#include "info.h"

//전투 메뉴
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

