#include "Store.h"

CStore::CStore()
{
}

CStore::~CStore()
{
}

bool CStore::Init(ItemArray* store)
{//파일 입력 받을 초기화
	FILE* FileStream = nullptr;

	//파일 입력
	fopen_s(&FileStream, "ItemList.itl", "rb");

	if (!FileStream)
		return false;

	// (*store).
	// store->
	// 위의 2개의 접근방법은 같은 접근방법이다.
	fread(&store->Count, sizeof(int), 1, FileStream); //아이템 개수 입력

	//아이템 개수만큼 아이템 정보 입력
	for (int i = 0; i < store->Count; ++i)
	{
		Item	item = {};
		fread(&item, sizeof(Item), 1, FileStream);

		// 실제 사용할 아이템을 동적할당으로 생성한다.
		Item* StoreItem = new Item;

		// 위에서 파일로부터 읽어온 정보를 실제 사용할 아이템의 메모리에 복사해준다.
		memcpy(StoreItem, &item, sizeof(Item));

		//상점 아이템 리스트에 아이템 저장
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

		// 인벤토리에 아이템을 추가해준다.
		Item* InvenItem = new Item;

		//int Size = sizeof(Item);

		memcpy(InvenItem, store->ItemList[ItemIndex], sizeof(Item));

	
	}
}
