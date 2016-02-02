#ifndef _CHARACTER_ITEM_ITEM_H_
#define _CHARACTER_ITEM_ITEM_H_

#include "SystemHub.h"
#include "DeviceManager.h"
#include "Vec2.h"
#include "Player.h"

class AItem
{
public:
	AItem(Vec2 position, int range, IMAGE_ASSET_NAME assetName, int maxCntLive = 30);
	virtual ~AItem();
	virtual void Update();
	void Draw();
	bool IsPickupItem(Player* player);
	bool GetIsEnd();
private:
	DeviceManager*	device;
	ImageData*		imageData;
	int				cntLive;
	GCircle			hitArea;

};


#endif








