#ifndef _DATAMANAGER_CHARACTERIMAGEDATA_H_
#define _DATAMANAGER_CHARACTERIMAGEDATA_H_

#include "ImageData.h"

class CharacterImageData : public ImageData
{
public:
	CharacterImageData(char* filePath, PlayerColorList colorList, AnimeData animeData): ImageData(animeData){

		Initialize();
		LoadData(filePath);
		ChangePlayerColor(colorList);

	}
	~CharacterImageData(){}
	PlayerColorList	GetPlayerColorList();
	void			SetPlayerFrameColor(unsigned int color);

private:
	void			ChangePlayerColor(PlayerColorList colorList);
};

#endif