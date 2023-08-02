#include "Battle.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Monster.h"

CBattle::CBattle()
{
}

CBattle::~CBattle()
{
}
//메뉴 
EBattleMenu CBattle::Menu()
{
	std::cout << "1. 공격" << std::endl;
	std::cout << "2. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EBattleMenu::None ||
		Input > (int)EBattleMenu::Back)
		return EBattleMenu::None;

	return (EBattleMenu)Input;
}
//공격 함수 
EBattleResult CBattle::Attack(CPlayer* Player, CMonster* Monster)
{
	//플레이어 입히는 데미지 = 플레이어 공격력 - 몬스터 공격력
	int	Damage = Player->GetAttack() - Monster->GetArmor();

	// 삼항연산자 : 조건을 체크하여 true일때와 false일때의 값을 지정할 수 있다.
	Damage = Damage < 1 ? 1 : Damage;

	// Damage 함수는 죽었을 경우 true가 반환된다.
	if (Monster->Damage(Damage))
	{
		//플레이어 경험치, 돈 획득
		Player->AddExp(Monster->GetExp());
		Player->AddMoney(Monster->GetMoney());
		return EBattleResult::MonsterDeath;
	}

	//플레이어가 입는 데미지
	Damage = Monster->GetAttack() - Player->GetArmor();

	Damage = Damage < 1 ? 1 : Damage;

	// 플레이어 사망시 부활
	if (Player->Damage(Damage)) //죽었을때 true
	{
		Player->Resurrection();
		return EBattleResult::PlayerDeath;
	}

	return EBattleResult::None;
}

//전투 타입 (난이도)
bool CBattle::Init(EBattleType Type)
{
	mBattleType = Type;

	return true;
}
//전투 실행 
void CBattle::Run()
{
	//플레이어 및 몬스터 호출
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	CMonster* Monster = CObjectManager::GetInst()->CreateMonster(mBattleType);

	while (true)
	{
		system("cls");

		//플레이어, 몬스터 정보 출력
		std::cout << "=================== Player ===================" << std::endl;
		Player->Output();
		std::cout << std::endl;


		std::cout << "=================== Monster ===================" << std::endl;
		Monster->Output();
		std::cout << std::endl;

		//공격에 따른 처리
		switch (Menu())
		{
		case EBattleMenu::Attack:
			switch (Attack(Player, Monster))
			{
			case EBattleResult::None:
				break;
			case EBattleResult::PlayerDeath:
				break;
			case EBattleResult::MonsterDeath: //몬스터 사망시 몬스터 제거후 새 몬스터 호출
				delete Monster;
				Monster = CObjectManager::GetInst()->CreateMonster(mBattleType);
				break;
			default:
				delete Monster;
				break;
			}
			break;
		case EBattleMenu::Back:
			return;
		}
	}
}
