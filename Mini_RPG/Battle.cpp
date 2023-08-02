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
//�޴� 
EBattleMenu CBattle::Menu()
{
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EBattleMenu::None ||
		Input > (int)EBattleMenu::Back)
		return EBattleMenu::None;

	return (EBattleMenu)Input;
}
//���� �Լ� 
EBattleResult CBattle::Attack(CPlayer* Player, CMonster* Monster)
{
	//�÷��̾� ������ ������ = �÷��̾� ���ݷ� - ���� ���ݷ�
	int	Damage = Player->GetAttack() - Monster->GetArmor();

	// ���׿����� : ������ üũ�Ͽ� true�϶��� false�϶��� ���� ������ �� �ִ�.
	Damage = Damage < 1 ? 1 : Damage;

	// Damage �Լ��� �׾��� ��� true�� ��ȯ�ȴ�.
	if (Monster->Damage(Damage))
	{
		//�÷��̾� ����ġ, �� ȹ��
		Player->AddExp(Monster->GetExp());
		Player->AddMoney(Monster->GetMoney());
		return EBattleResult::MonsterDeath;
	}

	//�÷��̾ �Դ� ������
	Damage = Monster->GetAttack() - Player->GetArmor();

	Damage = Damage < 1 ? 1 : Damage;

	// �÷��̾� ����� ��Ȱ
	if (Player->Damage(Damage)) //�׾����� true
	{
		Player->Resurrection();
		return EBattleResult::PlayerDeath;
	}

	return EBattleResult::None;
}

//���� Ÿ�� (���̵�)
bool CBattle::Init(EBattleType Type)
{
	mBattleType = Type;

	return true;
}
//���� ���� 
void CBattle::Run()
{
	//�÷��̾� �� ���� ȣ��
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	CMonster* Monster = CObjectManager::GetInst()->CreateMonster(mBattleType);

	while (true)
	{
		system("cls");

		//�÷��̾�, ���� ���� ���
		std::cout << "=================== Player ===================" << std::endl;
		Player->Output();
		std::cout << std::endl;


		std::cout << "=================== Monster ===================" << std::endl;
		Monster->Output();
		std::cout << std::endl;

		//���ݿ� ���� ó��
		switch (Menu())
		{
		case EBattleMenu::Attack:
			switch (Attack(Player, Monster))
			{
			case EBattleResult::None:
				break;
			case EBattleResult::PlayerDeath:
				break;
			case EBattleResult::MonsterDeath: //���� ����� ���� ������ �� ���� ȣ��
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
