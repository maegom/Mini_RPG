#pragma once

#include "Info.h"

//상점 클래스
class CStore
{
public:
	CStore();
	~CStore();

private:
	CArray<class CItem*>	mItemArray;

private:
	int Menu();

public:
	bool Init(const char* FileName);
	void Run();
};

