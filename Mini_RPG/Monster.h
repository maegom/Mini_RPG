#pragma once

#include "Character.h"

//���� Ŭ����
class CMonster :
	public CCharacter   //CCharacter Ŭ���� ���
{
public:
	CMonster();
	~CMonster();

	 

public:
	// "aaa" �̷� ���ڿ��� ���޹��� ��� const char* Ÿ���� ����Ѵ�.
	bool Init()	override;
	void Output()	override;
};
