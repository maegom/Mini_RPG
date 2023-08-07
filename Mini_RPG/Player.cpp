#include "Player.h"
#include "Item.h"

//플레이어 클래스 호출 함수. 변수 초기화
CPlayer::CPlayer() :
    mJob(EJob::None),
    mEquipItem {} //장착 아이템
{
}

//장착아이템이 있으면 동적할당 제거
CPlayer::~CPlayer()
{
    for (int i = 0; i < Equip_End; ++i)
    {
        if (nullptr != mEquipItem[i])
            delete mEquipItem[i];
    }
}
//공격력 호출
int CPlayer::GetAttack()
{
    int Attack = mAttack;

    // 방어력 = 플레이어 방어력 + 장비 방어력
    if (nullptr != mEquipItem[Equip_Weapon])
        Attack += mEquipItem[Equip_Weapon]->GetOption();

    return Attack;
}

//방어력 호출
int CPlayer::GetArmor()
{
    int Armor = mArmor;

    // 방어력 = 플레이어 방어력 + 장비 방어력
    if (nullptr != mEquipItem[Equip_Armor])
        Armor += mEquipItem[Equip_Armor]->GetOption();

    return Armor;
}

// 리턴이 true일 경우 장착, false일 경우 장착 실패이다.
// 2번째 인자는 이중포인터이다. 즉 포인터 변수의 메모리 주소를 담고 있다.
// 이를 역참조하게 되면 포인터 변수가 된다. 그래서 그 포인터 변수에 장착하고 있던
// 아이템의 메모리 주소를 넘겨준다.
bool CPlayer::Equip(CItem* ChangeItem, CItem** EquipItem)
{
    EEquipType Type = ChangeItem->GetEquipType();

    if (Type == Equip_None)
        return false;

    // 기존에 장착하고 있던 아이템의 주소를 인자로 넘어온 포인터 변수에
    // 대입해준다.
    *EquipItem = mEquipItem[Type];

    // 아이템을 교체한다.
    mEquipItem[Type] = ChangeItem;


    return true;
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

    //레벨 경험치 공격력 출력
    std::cout << "레벨 : " << mLevel << "\t경험치 : " << mExp << std::endl;
    std::cout << "공격력 : " << mAttack;

    // 장착무기가 있을 경우 무기의 공격력도 함께 표시해준다.
    if (nullptr != mEquipItem[Equip_Weapon])
        std::cout << " + " << mEquipItem[Equip_Weapon]->GetOption();

    //방어력 출력 
    std::cout << "\t방어력 : " << mArmor;

    if (nullptr != mEquipItem[Equip_Armor])
        std::cout << " + " << mEquipItem[Equip_Armor]->GetOption();

    std::cout << std::endl;

    //체력 마나 보유금액 장착무기 이름 출력 
    std::cout << "체력 : " << mHP << " / " << mHPMax << "\t마나 : " << mMP << " / " <<
        mMPMax << std::endl;
    std::cout << "보유금액 : " << mMoney << std::endl;
    std::cout << "장착무기 : ";

    if (nullptr != mEquipItem[Equip_Weapon])
    {
        std::cout << mEquipItem[Equip_Weapon]->GetName();
    }

    else
        std::cout << "없음";

    //장착 방어구 이름 출력
    std::cout << "\t장착방어구 : ";

    if (nullptr != mEquipItem[Equip_Armor])
    {
        std::cout << mEquipItem[Equip_Armor]->GetName();
    }

    else
        std::cout << "없음";

    std::cout << std::endl;
}
