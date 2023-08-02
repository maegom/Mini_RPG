#pragma once

#include "Info.h"

//상점 클래스
class CStore
{
public:
	CStore();
	~CStore();

private:
	class CItem* mItemArray;
	int			mItemCount;

private:
	int Menu();

public:
	bool Init(const char* FileName);
	void Run();
};

