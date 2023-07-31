#include "info.h"

int OutputItemList(const ItemArray* Array)
{
	system("cls"); //화면 정리 

	//개수만큼 이름 , 무기 종류, 가격 출력
	for (int i = 0; i < Array->Count; ++i)
	{
		std::cout << i + 1 << ". 이름 : " << Array->ItemList[i]->Name << "\t종류 : ";

		switch (Array->ItemList[i]->Type)
		{
		case EItemType::Weapon:
			std::cout << "무기\n";
			break;
		case EItemType::Armor:
			std::cout << "방어구\n";
			break;
		}

		std::cout << "Price : " << Array->ItemList[i]->Price << "\tSell : "
			<< Array->ItemList[i]->Sell << std::endl;
	}

	//가방속 아이템 개수 +1 번째에 뒤로가기 
	std::cout << Array->Count + 1 << ". 뒤로가기" << std::endl;
	std::cout << "번호를 선택하세요 : ";

	//입력 받아 행동 취할 수 있게
	int	Input;
	std::cin >> Input;

	if (Input < 1 || Input > Array->Count + 1)
		return -1;

	return Input;
}
