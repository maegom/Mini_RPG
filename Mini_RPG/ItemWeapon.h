#pragma once
#include "Item.h"
class CItemWeapon :
    public CItem
{
public:
    CItemWeapon();
    CItemWeapon(const CItemWeapon& ref);
    ~CItemWeapon();

public:
    virtual bool Init();
    virtual void Output();
};

