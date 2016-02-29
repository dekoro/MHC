#include "ImageRenderer.h"
#include"NowLoading.h"
#include<DxLib.h>


ImageRenderer::ImageRenderer(){
	SetupImageMap();

}

ImageRenderer::~ImageRenderer(){

}

void ImageRenderer::Update(){
	for each (pair<int, ImageData*> image in characterImageMap){
		characterImageMap[image.first]->UpdateAnime();
	}
}

void ImageRenderer::DrawPlayerCenter(int imageIndex, Vec2 positionCenter){
	int imageHandle = characterImageMap[imageIndex]->GetImageHandle();
	DrawLT(imageHandle, positionCenter.GetIntX() - GetSizeHalfImageX(imageIndex), positionCenter.GetIntY() - GetSizeHalfImageY(imageIndex));
}

//プレイヤー専用？のグラフィックハンドル取得メソッド
int ImageRenderer::GetHGraphics(int index)
{
	return characterImageMap[index]->GetImageHandle();
}

void ImageRenderer::DrawCeter(IMAGE_ASSET_NAME assetName, Vec2 posCenter){
	//DrawCeter(assetName, posCenter.GetIntX(), posCenter.GetIntY());
	DrawBillboard3D(VGet(posCenter.X, posCenter.Y, 0), 0.5f, 0.5f, imageMap[assetName]->GetSizeHalfImageX() * 2, 0.0f, imageMap[assetName]->GetImageHandle(),TRUE);
}

void ImageRenderer::DrawRotation(IMAGE_ASSET_NAME asset, int posCX, int posCY, double angleDeg){
	int imgHdl = imageMap[asset]->GetImageHandle();
	DrawRotation(imgHdl, posCX, posCY, angleDeg);
}

void ImageRenderer::DrawLT(int imageHandle, Vec2 position){
	Draw(imageHandle, position.GetIntX(), position.GetIntY());
}

void ImageRenderer::DrawLTUseToShader(int imageHandle, Vec2 position){
	DrawUseToShader(imageHandle, position.GetIntX(), position.GetIntY());
}


void ImageRenderer::DrawLT(int imageHandle, Vec2 position,float scale){
	Draw(imageHandle, position.GetIntX(), position.GetIntY(),scale);
}

void ImageRenderer::DrawLT(int imageHandle, int posX, int posY, float scale){
	Draw(imageHandle, posX, posY, scale);
}

//背景
void ImageRenderer::DrawBackGround(){
	Draw(imageMap[imageAsset_Title_BackGround]->GetImageHandle(),VGet(0,0,0),10 );
}

int  ImageRenderer::AddCharacterImageMap(IMAGE_ASSET_NAME pathIndex, PlayerColorList plColorList){
	int imageIndex = characterImageMap.size();
	characterImageMap.insert(map<int, CharacterImageData*>::value_type(imageIndex, new CharacterImageData( imageFilePathMap[pathIndex], plColorList, animeDataMap[pathIndex])));
	return imageIndex;
}

void ImageRenderer::RemoveBaseImageMap(IMAGE_ASSET_NAME assetName){
	FAST_RETURN_AND_ERROR_VOID(!CheckConnotationBaseImageMap(assetName), "");
	SAFE_DELETE(imageMap[assetName]);
	imageMap.erase(assetName);
}

void ImageRenderer::RemoveCharacterImageMap(int imageIndex){
	FAST_RETURN_AND_ERROR_VOID(!CheckConnotationCharacterImageMap(imageIndex), "");
	SAFE_DELETE(characterImageMap[imageIndex]);
	characterImageMap.erase(imageIndex);
}

void ImageRenderer::ChangeImageType(int imageIndex, int type){
	characterImageMap[imageIndex]->SetAnimeType(type);
}

void ImageRenderer::ChangeAnimePlay(int imageIndex, bool isPlay){
	characterImageMap[imageIndex]->SetAnimePlay(isPlay);
}

void ImageRenderer::ClearImageMap(){
	for each (pair<int, ImageData*> imageData in characterImageMap){
		RemoveCharacterImageMap(imageData.first);
	}
	for each (pair<IMAGE_ASSET_NAME const, ImageData*> imageData in imageMap){
		RemoveBaseImageMap(imageData.first);
	}
}

AnimeData ImageRenderer::GetAnimeData(IMAGE_ASSET_NAME animeDataIndex){
	return animeDataMap[animeDataIndex];
}

ImageData* ImageRenderer::CopyImageData(IMAGE_ASSET_NAME asset){
	return new ImageData(*imageMap[asset]);
}

Vec2 ImageRenderer::GetCharacterImageHalfSize(int imageIndex){
	return Vec2::Setup((float)characterImageMap[imageIndex]->GetSizeHalfImageX(), (float)characterImageMap[imageIndex]->GetSizeHalfImageY());
}

void ImageRenderer::DrawExtend(int imageHandle, int x, int y, float angle, float rate)
{
	DrawRotaGraph(x, y, rate, angle, imageHandle, TRUE);
}

//---private---

void ImageRenderer::SetupImageFilePathMap(){
	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_player_fighter		, "./Resource/FIGHTER_WALK.bmp"));

	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_Enemy_Bat			, "./Resource/Enemy_Bat.png"));
	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_Enemy_Ghost			, "./Resource/Enemy_Ghost.png"));
	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_Enemy_BigPumpkin	, "./Resource/Enemy_KingPumpkin.png"));

	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_Item_Lollipop		, "./Resource/Item_Lollipop.png"));

	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_Title_BackGround	, "./Resource/Title_BackGround.png"));
	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_Title_PushButton	, "./Resource/Title_PushXButton.png"));
	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_GameMain_BackGround	, "./Resource/GameMain_BackGround.png"));

	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_GameClear_BackGround, "./Resource/GameClear_BackGround.png"));
	imageFilePathMap.insert(map<IMAGE_ASSET_NAME, char*>::value_type(imageAsset_GameOver_BackGround, "./Resource/GameOver_BackGround.png"));
}

void ImageRenderer::SetupAnimeDataMap(){
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_player_fighter		, AnimeData::Setup(4, 8,   32,  32, 10, true)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_player_mage			, AnimeData::Setup(4, 8,   32,  32, 10, true)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_player_thief		, AnimeData::Setup(4, 8,   32,  32, 10, true)));

	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_player_fighter_BIG	, AnimeData::Setup(4, 4,   64,  64, 10, true)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_player_mage_BIG		, AnimeData::Setup(4, 4,   64,  64, 10, true)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_player_thief_BIG	, AnimeData::Setup(4, 4,   64,  64, 10, true)));
	 
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_Enemy_Test			, AnimeData::Setup(1, 1,   64,  64,  0, false)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_Enemy_Bat			, AnimeData::Setup(1, 1,   64,  64,  0, false)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_Enemy_Ghost			, AnimeData::Setup(1, 1,   64,  64,  0, false)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_Enemy_BigPumpkin	, AnimeData::Setup(1, 2,  256, 256,  0, false)));

	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_Item_Candy			, AnimeData::Setup(1, 1,   32,  32,  0, false)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_Item_Lollipop		, AnimeData::Setup(1, 1,   32,  32,  0, false)));
	
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_Title_BackGround	, AnimeData::Setup(1, 1, 1280, 720,  0, false)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_Title_PushButton	, AnimeData::Setup(1, 1,  696,  88,  0, false)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_GameMain_BackGround, AnimeData::Setup(1, 1, 1280, 720, 0, false)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_GameOver_BackGround, AnimeData::Setup(1, 1, 1280, 720, 0, false)));
	animeDataMap.insert(map<IMAGE_ASSET_NAME, AnimeData>::value_type(imageAsset_GameClear_BackGround, AnimeData::Setup(1, 1, 1280, 720, 0, false)));
}

void ImageRenderer::SetupImageMapInstance(){
	SetUseASyncLoadFlag(TRUE);
	AddImageMap(imageAsset_player_fighter);
	AddImageMap(imageAsset_Enemy_Bat);
	AddImageMap(imageAsset_Enemy_Ghost);
	AddImageMap(imageAsset_Enemy_BigPumpkin);
	AddImageMap(imageAsset_Item_Lollipop);
	AddImageMap(imageAsset_Title_BackGround);
	AddImageMap(imageAsset_Title_PushButton);
	AddImageMap(imageAsset_GameMain_BackGround);
	AddImageMap(imageAsset_GameOver_BackGround);
	AddImageMap(imageAsset_GameClear_BackGround);
	SetUseASyncLoadFlag(FALSE);
	NowLoading("Resource/Title_BackGround.png");
}

void ImageRenderer::AddImageMap(IMAGE_ASSET_NAME assetName){
	FAST_RETURN_AND_ERROR_VOID(CheckConnotationBaseImageMap(assetName), STR("アセット名[",to_string(assetName)+"]はすでにsoundMapに登録されています。"));
	int imgHdl = LoadGraph(imageFilePathMap[assetName]);
	FAST_RETURN_AND_ERROR_VOID((imgHdl == -1), STR("ファイルパス\"",imageFilePathMap[assetName]+"\"を読み込もうとしましたが失敗しました。ファイルパスを確認して下さい。"));
	CheckNumAndSize(imgHdl, &animeDataMap[assetName].XNum, &animeDataMap[assetName].typeNum, &animeDataMap[assetName].oneSizeX, &animeDataMap[assetName].oneSizeY);
	imageMap.insert(map<IMAGE_ASSET_NAME, ImageData*>::value_type(assetName, new ImageData(imageFilePathMap[assetName], animeDataMap[assetName])));
}

void ImageRenderer::SetupImageMap(){
	SetupImageFilePathMap();
	SetupAnimeDataMap();
	SetupImageMapInstance();
}

void ImageRenderer::Draw(int imageHandle, int posX, int posY){
	int x,y ;
	GetGraphSize(imageHandle,&x,&y);
	DrawBillboard3D(VGet(posX, posY, 0), 0.5f, 0.5f, x, 0.0f, imageHandle, TRUE);
}

void ImageRenderer::Draw(int imageHandle, int posX, int posY , float scale){
	int x, y;
	GetGraphSize(imageHandle, &x, &y);
	DrawBillboard3D(VGet(posX, posY, 0), 0.5f, 0.5f, scale*x, 0.0f, imageHandle, TRUE);
}

void ImageRenderer::DrawUseToShader(int imageHandle, int posX, int posY){
	int x, y;
	GetGraphSize(imageHandle, &x, &y);
	DrawBillboard3D(VGet(posX, posY, 0), 0.5f, 0.5f, x, 0.0f, imageHandle, TRUE);

}

//ハンドル　中心　拡大率
void  ImageRenderer::Draw(int imageHandle,VECTOR pos,float scale)
{
	int x, y;//なんかGetSizeHalfImageYが正常に動かないのでとりあえず毎フレーム半径を取得する
	GetGraphSize(imageHandle,&x,&y);
/*
	DrawModiBillboard3D(VGet(0, 0, 0), (-GetSizeHalfImageX(imageHandle) / 2) * scale, (GetSizeHalfImageY(imageHandle) / 2) * scale,
		(GetSizeHalfImageX(imageHandle) / 2) * scale, (GetSizeHalfImageY(imageHandle) / 2) * scale,
		(GetSizeHalfImageX(imageHandle) / 2) * scale, (-GetSizeHalfImageY(imageHandle) / 2) * scale,
		(-GetSizeHalfImageX(imageHandle) / 2) * scale, (-GetSizeHalfImageY(imageHandle) / 2) * scale,
		imageHandle,
		TRUE);*/
	DrawModiBillboard3D(VGet(0, 0, 0), (-x / 2) * scale, (y/ 2) * scale,
		(x/ 2) * scale, (y/ 2) * scale,
		(x/ 2) * scale, (-y/ 2) * scale,
		(-x/ 2) * scale, (-y/ 2) * scale,
		imageHandle,
		TRUE);
}

void ImageRenderer::DrawRotation(int imageHandle, int posX, int posY, double angleDeg){
	double angleRad = angleDeg / 180.0*DX_PI;
	//DrawRotaGraph(posX, posY, 1.0, angleRad, imageHandle, TRUE, FALSE);
	Draw(imageHandle,posX,posY);
}

bool ImageRenderer::CheckConnotationCharacterImageMap(int index){
	return(characterImageMap.find(index) != characterImageMap.end());
}

bool ImageRenderer::CheckConnotationBaseImageMap(IMAGE_ASSET_NAME assetName){
	return(imageMap.find(assetName) != imageMap.end());
}
int ImageRenderer::GetSizeHalfImageX(int imageIndex){
	return characterImageMap[imageIndex]->GetSizeHalfImageX();
}

int ImageRenderer::GetSizeHalfImageY(int imageIndex){
	return characterImageMap[imageIndex]->GetSizeHalfImageY();
}

void ImageRenderer::CheckNumAndSize(int imageHandle, int* numX, int* numY, int* sizeX, int* sizeY){
	*numX = (*numX > 0) ? *numX : 1;
	*numY = (*numY > 0) ? *numY : 1;
	if (*sizeX > 0 && *sizeY > 0){ return;  }
	GetGraphSize(imageHandle, sizeX, sizeY);
}

int ImageRenderer::GetMapTipHundle(int num)
{
	if (num == -1)
		return 15;

	return	this->mapTip[num];
}

int ImageRenderer::GetMapTipSizeX()
{
	return this->mapTipSizeX;
}

int ImageRenderer::GetMapTipSizeY()
{
	return this->mapTipSizeY;
}

void ImageRenderer::LoadMapTip(std::string filePath,int xNum,int yNum,int totalNum)
{
	int *gra = new int[totalNum];
	this->mapTip.resize(totalNum);
	int resourceGraphics = LoadGraph(filePath.c_str());
	int x = 0, y = 0;//もと画像のサイズ
	int localSizeX = 0, localSizeY = 0;
	GetGraphSize(resourceGraphics,&x,&y);

	localSizeX = x / xNum;
	localSizeY= y / yNum;

	this->mapTipSizeX = localSizeX;

	this->mapTipSizeY = localSizeY;

	LoadDivGraph(filePath.c_str(), totalNum, xNum, yNum, localSizeX, localSizeY, gra);

	//ローカル変数からメンバ変数への詰め替え
	for (int i = 0; i < totalNum; ++i)
	{
		this->mapTip[i] = gra[i];
	}

	delete[] gra;
}

std::vector<int> ImageRenderer::LoadMotion(std::string filePath, int xNum, int yNum, int startNum, int totalNum, int totalMotionNum)
{
	std::vector<int> tempMotion;

	tempMotion.resize(totalMotionNum);

	int *gra = new int[totalNum];
	int resourceGraphics = LoadGraph(filePath.c_str());
	int x = 0, y = 0;//もと画像のサイズ
	int localSizeX = 0, localSizeY = 0;
	int count = 0;
	GetGraphSize(resourceGraphics, &x, &y);

	localSizeX = x / xNum;
	localSizeY = y / yNum;

	this->mapTipSizeX = localSizeX;

	this->mapTipSizeY = localSizeY;

	LoadDivGraph(filePath.c_str(), totalNum, xNum, yNum, localSizeX, localSizeY, gra);

	for (int i = startNum; i < startNum + totalMotionNum; i++)
	{
		tempMotion[count++] = gra[i];
	}

	delete[] gra;

	return tempMotion;
}