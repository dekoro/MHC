#ifndef _CHARACTER_ITEM_ITEMMANAGER_H_
#define _CHARACTER_ITEM_ITEMMANAGER_H_

#include "SystemHub.h"
class AItem;
class Player;

class ItemManager
{
public:
	ItemManager(){}
	~ItemManager();

	void CheckHitPlayer(Player* player);
	void Initialize();
	void Update();
	void Draw();
	void Finalize();
	int	 GetCountGetItem();

private:
	std::vector<AItem*> itemList;
	int cntGetItem;

	void RefleshItemList();
	void DeleteItemList(int index);
	void ClearItemList();
	void CountupGetItem();
};




#endif




