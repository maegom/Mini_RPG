#include "Store.h"

CStore::CStore()
{
}

CStore::~CStore()
{
}

bool CStore::Init(ItemArray* store)
{//���� �Է� ���� �ʱ�ȭ
	FILE* FileStream = nullptr;

	//���� �Է�
	fopen_s(&FileStream, "ItemList.itl", "rb");

	if (!FileStream)
		return false;

	// (*store).
	// store->
	// ���� 2���� ���ٹ���� ���� ���ٹ���̴�.
	fread(&store->Count, sizeof(int), 1, FileStream); //������ ���� �Է�

	//������ ������ŭ ������ ���� �Է�
	for (int i = 0; i < store->Count; ++i)
	{
		Item	item = {};
		fread(&item, sizeof(Item), 1, FileStream);

		// ���� ����� �������� �����Ҵ����� �����Ѵ�.
		Item* StoreItem = new Item;

		// ������ ���Ϸκ��� �о�� ������ ���� ����� �������� �޸𸮿� �������ش�.
		memcpy(StoreItem, &item, sizeof(Item));

		//���� ������ ����Ʈ�� ������ ����
		store->ItemList[i] = StoreItem;
	}

	fclose(FileStream);

	return true;
}

void CStore::Run(ItemArray* store)
{
	while (true)
	{
		int Input = OutputItemList(store);

		if (Input == -1)
			continue;

		else if (Input == store->Count + 1)
			break;

		int	ItemIndex = Input - 1;

		// �κ��丮�� �������� �߰����ش�.
		Item* InvenItem = new Item;

		//int Size = sizeof(Item);

		memcpy(InvenItem, store->ItemList[ItemIndex], sizeof(Item));

	
	}
}
