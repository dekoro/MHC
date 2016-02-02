#ifndef _DATAMANAGER_IMAGEDATA_H_
#define _DATAMANAGER_IMAGEDATA_H_

#include "GSystemHub.h"
#include "GSystem.h"


class ImageData
{
public:
	ImageData(){}
	ImageData(AnimeData animeData);
	ImageData(char* filePath, AnimeData animeData);
	~ImageData();
	void			Initialize();
	void			SetAnimeType(int type);
	void			SetAnimePlay(bool isPlay);
	void			SetAnimeSkipFrame(int animeSkipFrame);
	void			SetIsLoop(bool isLoop);
	virtual int		GetImageHandle();
	int				GetSizeHalfImageX();
	int				GetSizeHalfImageY();
	void			UpdateAnime();
	void			ResetAnimeCount();

protected:
	AnimeData		animeData;
	int				nowType;
	int				nowFrame;
	int				dataHandle[ANIME_FRAME_NUM];
	void			LoadData(char* filePath);

private:
	int				animeCount;

	void			ResetAnimeDrawFrame();
	void			ResetDataHandle	();
};

#endif