#pragma once

#include "Character.h"

//몬스터 클래스
class CMonster :
	public CCharacter   //CCharacter 클래스 상속
{
public:
	CMonster();
	~CMonster();

	 

public:
	// "aaa" 이런 문자열을 전달받을 경우 const char* 타입을 사용한다.
	bool Init()	override;
	void Output()	override;
};
