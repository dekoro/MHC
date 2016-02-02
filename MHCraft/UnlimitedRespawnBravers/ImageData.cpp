#include "ImageData.h"

ImageData::ImageData( char* filePath, AnimeData animeData){
	Initialize();
	this->animeData = animeData;
	LoadData(filePath);
}

ImageData::ImageData(AnimeData animeData){
	Initialize();
	this->animeData = animeData;
}

ImageData::~ImageData(){
}

void ImageData::Initialize(){
	ResetDataHandle();
	ResetAnimeCount();
	ResetAnimeDrawFrame();
}

void ImageData::SetAnimeType(int type){
	FAST_RETURN_AND_ERROR_VOID((type < 0 || type > animeData.typeNum), "指定されたTypeがありません。");
	this->nowType = type;
}

void ImageData::SetAnimePlay(bool isPlay){
	this->animeData.isAnimation = isPlay;
}

void ImageData::SetIsLoop(bool isLoop){
	this->animeData.isLoop = isLoop;
}

void ImageData::SetAnimeSkipFrame(int animeSkipFrame){
	this->animeData.skipFrame = animeSkipFrame;
}

int  ImageData::GetImageHandle(){
	return dataHandle[nowType*animeData.XNum + nowFrame];
}

int  ImageData::GetSizeHalfImageX(){
	return (int)(animeData.oneSizeX / 2);
}

int  ImageData::GetSizeHalfImageY(){
	return (int)(animeData.oneSizeY / 2);
}

void ImageData::UpdateAnime(){
	if (!animeData.isAnimation){ return; }
	animeCount--;
	if (animeCount > 0){ return; }
	ResetAnimeCount();
	nowFrame++;
	if (nowFrame < animeData.XNum){ return; }
	nowFrame = 0;
}

void ImageData::ResetAnimeCount(){
	animeCount = animeData.skipFrame;
}

//---protected---
void ImageData::LoadData(char* filePath){
	int resoultLoad;
	resoultLoad = LoadDivGraph(filePath, animeData.GetFrameAllNum()
							 , animeData.XNum, animeData.typeNum
							 , animeData.oneSizeX, animeData.oneSizeY
							 , dataHandle);

	if (resoultLoad == -1){
		Debug::Alert("ファイルの読み込みに失敗しました。");
	}
}

//---private---

void ImageData::ResetAnimeDrawFrame(){
	nowFrame	= 0;
	nowType		= 0;
}

void ImageData::ResetDataHandle(){
	for (int i = 0; i < ANIME_FRAME_NUM; i++){
		dataHandle[i] = 0;
	}
}





