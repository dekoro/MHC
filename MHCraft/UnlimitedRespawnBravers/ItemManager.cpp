#include "ItemManager.h"

ItemManager::~ItemManager(){
	ClearItemList();
}

void ItemManager::CheckHitPlayer(Player* player){
	for each(AItem* item in itemList){
		if (item->IsPickupItem(player)){
			CountupGetItem();
		}
	}
}

void ItemManager::Initialize(){
	managers = Managers::GetInstance();
	ClearItemList();
	cntGetItem = 0;
}

SceneMediateData ItemManager::Update(){
	for each(AItem* item in itemList){
		item->Update();
	}
	RefleshItemList();
	return SceneMediateData::Setup(SCENE_GAMEMAIN);

}

void ItemManager::Draw(){
	for each(AItem* item in itemList){
		item->Draw();
	}
}

void ItemManager::Finalize(){

}

void ItemManager::AddItemLollipop(Vec2 position){
	DeviceManager::GetInstance()->Sound()->Play(SE_Drop);
	itemList.push_back(new ItemLollipop(position));
}

int	 ItemManager::GetCountGetItem(){
	return cntGetItem;
}

//-----private-----

void ItemManager::RefleshItemList(){
	int num = itemList.size();
	for (int i = 0; i < num; i++){
		if (!itemList[i]->GetIsEnd()){ continue; }
		DeleteItemList(i);
		i--;
		num--;
	}
}

void ItemManager::DeleteItemList(int index){
	SAFE_DELETE(itemList[index]);
	itemList.erase(itemList.begin()+index);

}

void ItemManager::ClearItemList(){
	while (!itemList.empty()){
		DeleteItemList(0);
	}
}

void ItemManager::CountupGetItem(){
	cntGetItem++;
}







