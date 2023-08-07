#pragma once

#include "Info.h"

class CObject
{
public:
	CObject();
	virtual ~CObject();

protected:
	char	mName[32];

public:
	virtual bool Init();
	virtual void Output();
};

