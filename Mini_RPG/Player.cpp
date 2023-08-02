#include "Player.h"

//플레이어 클래스 호출 함수. 변수 초기화
CPlayer::CPlayer() :
    mName{},
    mJob(EJob::None),
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

CPlayer::~CPlayer()
{
}

//초기화 
bool CPlayer::Init()
{
    //시작시 이름 및 직업 선택
    std::cout << "이름 : ";
    std::cin >> mName;

    while (true)
    {
        system("cls");
        std::cout << "1. 기사" << std::endl;
        std::cout << "2. 궁수" << std::endl;
        std::cout << "3. 마법사" << std::endl;
        std::cout << "직업을 선택하세요 : ";
        int Job;

        std::cin >> Job;

        if (Job > (int)EJob::None && Job < (int)EJob::End)
        {
            mJob = (EJob)Job;
            break;
        }
    }

    //직업에 따른 세부 스텟 
    switch (mJob)
    {
    case EJob::Knight:
        mAttack = 30;
        mArmor = 20;
        mHP = 500;
        mHPMax = 500;
        mMP = 100;
        mMPMax = 100;
        break;
    case EJob::Archer:
        mAttack = 40;
        mArmor = 15;
        mHP = 400;
        mHPMax = 400;
        mMP = 200;
        mMPMax = 200;
        break;
    case EJob::Magicion:
        mAttack = 50;
        mArmor = 10;
        mHP = 300;
        mHPMax = 300;
        mMP = 300;
        mMPMax = 300;
        break;
    }

    //시작 정보
    mLevel = 1;
    mExp = 0;
    mMoney = 10000;

    return true;
}

//플레이어 정보 출력 함수
void CPlayer::Output()
{
    std::cout << "이름 : " << mName << "\t직업 : ";

    switch (mJob)
    {
    case EJob::Knight:
        std::cout << "기사" << std::endl;
        break;
    case EJob::Archer:
        std::cout << "궁수" << std::endl;
        break;
    case EJob::Magicion:
        std::cout << "마법사" << std::endl;
        break;
    }

    std::cout << "레벨 : " << mLevel << "\t경험치 : " << mExp << std::endl;
    std::cout << "공격력 : " << mAttack << "\t방어력 : " << mArmor << std::endl;
    std::cout << "체력 : " << mHP << " / " << mHPMax << "\t마나 : " << mMP << " / " <<
        mMPMax << std::endl;
    std::cout << "보유금액 : " << mMoney << std::endl;
}
