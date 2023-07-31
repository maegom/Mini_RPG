#include "InventoryManager.h"

CInventoryManager::CInventoryManager()
{
}

CInventoryManager::~CInventoryManager()
{
}

bool CInventoryManager::Init(ItemArray* Inventory)
{
    //파일 받을 공간 초기화
    FILE* FileStream = nullptr;

    //바이너리 파일 읽기
    fopen_s(&FileStream, "Inventory.inv", "rb");

    if (!FileStream)
        return true;

    //닫기
    fclose(FileStream);

    return true;
}

void CInventoryManager::Run(ItemArray* Inventory)
{
    while (true)
    {
        // 입력값 (장비 번호 또는 뒤로가기) 받아 수행 
        int Input = OutputItemList(Inventory);

        //예외처리 재입력 
        if (Input == -1)
            continue;

        //뒤로가기
        else if (Input == Inventory->Count + 1)
            break;

        //장비 번호는 1부터이므로 -1
        int ItemIndex = Input - 1;


        break;
    }

}
