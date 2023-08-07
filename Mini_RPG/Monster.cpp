#include "Monster.h"

CMonster::CMonster()  
{
}

CMonster::~CMonster()
{
}

//몬스터 정보 설정
bool CMonster::Init()
{
    return true;
}

//몬스터 정보 출력 함수
void CMonster::Output()
{
    std::cout << "이름 : " << mName << "\t레벨 : " << mLevel << std::endl;
    std::cout << "공격력 : " << mAttack << "\t방어력 : " << mArmor << std::endl;
    std::cout << "체력 : " << mHP << " / " << mHPMax << "\t마나 : " << mMP << " / " <<
        mMPMax << std::endl;
    std::cout << "획득금액 : " << mMoney << "\t획득경험치 : " << mExp << std::endl;
}
