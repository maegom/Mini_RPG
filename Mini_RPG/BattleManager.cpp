#include "BattleManager.h"

CBattleManager::CBattleManager()
{
}

CBattleManager::~CBattleManager()
{
}

bool CBattleManager::Init()
{
	return true;
}

EBattleMenu CBattleManager::Menu()
{
	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. �����" << std::endl;
	std::cout << "4. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";

	// ���ð� �Է�
	int Input;
	std::cin >> Input;

	//�Է� ���� ����ó��
	if (Input <= (int)EBattleMenu::None || Input > (int)EBattleMenu::Back)
		return EBattleMenu::None;

	//�Է½� �Է°� ��ȯ
	return (EBattleMenu)Input;
}

//����
void CBattleManager::Run()
{
	while (true)
	{
		switch (Menu())
		{

		case EBattleMenu::Easy:
			break;
		case EBattleMenu::Normal:
			break;
		case EBattleMenu::Hard:
			break;
		case EBattleMenu::Back:
			return;
		}
	}
}

