#ifndef _DATAMANAGER_CHARACTERIMAGEDATA_H_
#define _DATAMANAGER_CHARACTERIMAGEDATA_H_

#include "ImageData.h"

class CharacterImageData : public ImageData
{
public:
	CharacterImageData(char* filePath, AnimeData animeData): ImageData(animeData){

		Initialize();
		LoadData(filePath);

	}
	~CharacterImageData(){}

private:
};

#endif