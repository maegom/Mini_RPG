#include "Monster.h"

//몬스터 정보 0으로 초기화
CMonster::CMonster() :
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

CMonster::~CMonster()
{
}

//몬스터 정보 설정
bool CMonster::Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
    int Exp, int Money)
{
    // 오른쪽 인자의 문자열을 왼쪽 인자에 복사해준다.
    strcpy_s(mName, Name);
    mAttack = Attack;
    mArmor = Armor;
    mHP = HP;
    mHPMax = HP;
    mMP = MP;
    mMPMax = MP;
    mLevel = Level;
    mExp = Exp;
    mMoney = Money;

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
