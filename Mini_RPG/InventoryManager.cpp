#include "InventoryManager.h"

CInventoryManager::CInventoryManager()
{
}

CInventoryManager::~CInventoryManager()
{
}

bool CInventoryManager::Init(ItemArray* Inventory)
{
    //���� ���� ���� �ʱ�ȭ
    FILE* FileStream = nullptr;

    //���̳ʸ� ���� �б�
    fopen_s(&FileStream, "Inventory.inv", "rb");

    if (!FileStream)
        return true;

    //�ݱ�
    fclose(FileStream);

    return true;
}

void CInventoryManager::Run(ItemArray* Inventory)
{
    while (true)
    {
        // �Է°� (��� ��ȣ �Ǵ� �ڷΰ���) �޾� ���� 
        int Input = OutputItemList(Inventory);

        //����ó�� ���Է� 
        if (Input == -1)
            continue;

        //�ڷΰ���
        else if (Input == Inventory->Count + 1)
            break;

        //��� ��ȣ�� 1�����̹Ƿ� -1
        int ItemIndex = Input - 1;


        break;
    }

}
