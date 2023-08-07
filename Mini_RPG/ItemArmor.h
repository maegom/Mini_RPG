#pragma once
#include "Item.h"
class CItemArmor :
    public CItem
{
public:
    CItemArmor();
    CItemArmor(const CItemArmor& ref);
    ~CItemArmor();

public:
    virtual bool Init();
    virtual void Output();
};

