#include "AItem.h"


AItem::AItem(Vec2 position, int range, IMAGE_ASSET_NAME assetName, int maxCntLive){
	device		= DeviceManager::GetInstance();
	imageData	= device->Image()->CopyImageData(assetName);
	cntLive		= maxCntLive;
	hitArea		= GCircle::Setup(position, range);
}

AItem::~AItem(){
	SAFE_DELETE(imageData);
}

void AItem::Update(){
	cntLive--;
}

void AItem::Draw(){
	if (cntLive > 60 || cntLive % 4 <= 2){
		Vec2 posCenter = hitArea.posCenter - Vec2::Setup((float)imageData->GetSizeHalfImageX(), (float)imageData->GetSizeHalfImageY());
		device->Image()->DrawLT(imageData->GetImageHandle(), posCenter);
	}
}

bool AItem::IsPickupItem(Player* player){
	if (GMath::CheckHitCircleToCircle(player->GetHitArea(), hitArea)){
		DeviceManager::GetInstance()->Sound()->Play(SE_Get);
		cntLive = 0;
		player->Heal(2);
		return true;
	}
	return false;
}

bool AItem::GetIsEnd(){
	return (cntLive <= 0);
}



