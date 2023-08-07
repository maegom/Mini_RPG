#include "Character.h"

CCharacter::CCharacter() :
    mName{},
    mAttack(0),
    mArmor(0),
    mHP(0),
    mHPMax(0),
    mMP(0),
    mMPMax(0),
    mLevel(0),
    mExp(0),
    mMoney(0)
{
}

CCharacter::~CCharacter()
{
}

bool CCharacter::Init()
{
    return false;
}

void CCharacter::Output()
{
}
