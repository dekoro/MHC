#ifndef _DEVICE_RENDERER_IMAGERENDERER_H_
#define _DEVICE_RENDERER_IMAGERENDERER_H_
#include "GSystemHub.h"
#include "ImageData.h"
#include "CharacterImageData.h"

enum IMAGE_ASSET_NAME{
	imageAsset_player_fighter,
	imageAsset_player_mage,
	imageAsset_player_thief,
	imageAsset_player_fighter_BIG,
	imageAsset_player_mage_BIG,
	imageAsset_player_thief_BIG,
	imageAsset_Enemy_Test,
	imageAsset_Enemy_Bat,
	imageAsset_Enemy_Ghost,
	imageAsset_Enemy_BigPumpkin,
	imageAsset_Item_Candy,
	imageAsset_Item_Lollipop,
	imageAsset_Title_BackGround,
	imageAsset_Title_PushButton,
	imageAsset_GameMain_BackGround
};

class ImageRenderer{
public:

	ImageRenderer();
	~ImageRenderer();

	void		Update();
	void		DrawPlayerCenter(int imageIndex, Vec2 positionCenter);
	void		DrawCeter(IMAGE_ASSET_NAME assetName, Vec2 posCenter);
	void		DrawCeter(IMAGE_ASSET_NAME assetName, int posCX, int posCY);
	void		DrawRotation(IMAGE_ASSET_NAME asset, int posCX, int posCY, double angleDeg);
	void		DrawRotation(int imageHandle, int posX, int posY, double angleDeg);
	void		DrawLT(int imageHandle, Vec2 position);
	void		DrawLT(int imageHandle, Vec2 position, float scale);
	void		DrawLT(int imageHandle, int posX, int posY);
	void		DrawBackGround();
	void		ChangeImageType(int imageIndex, int	type);
	void		ChangeAnimePlay(int imageIndex, bool isPlay);
	int			AddCharacterImageMap(IMAGE_ASSET_NAME pathIndex, PlayerColorList playerColorList);
	void		RemoveBaseImageMap(IMAGE_ASSET_NAME assetName);
	void		RemoveCharacterImageMap(int imageMap);
	void		ClearImageMap();
	AnimeData	GetAnimeData(IMAGE_ASSET_NAME animeDataIndex);
	void		AddCountPlayerAnimation(IMAGE_ASSET_NAME);
	ImageData*	CopyImageData(IMAGE_ASSET_NAME);
	Vec2		GetCharacterImageHalfSize(int imageIndex);


	///////////追加↓////////
	int GetHGraphics(int index);

	int GetMapTipHundle(int num);

	//現段階では１枚しかマップチップを読み込まないので注意
	//ファイルパス 横の数　縦の数　総分割数 
	void LoadMapTip(std::string filePath, int xNum, int yNum,int totalNum);

	int GetMapTipSizeX();
	int GetMapTipSizeY();
	
	//アニメーション読み込み
	//ファイルパス 横の数　縦の数　総分割数 
	std::vector<int> LoadMotion(std::string filePath, int xNum, int yNum,int startNum, int totalNum,int totalMotionNum);


private:
	map<int, CharacterImageData*>		characterImageMap;
	map<IMAGE_ASSET_NAME, ImageData*>	imageMap;
	map<IMAGE_ASSET_NAME, char*>		imageFilePathMap;
	map<IMAGE_ASSET_NAME, AnimeData>	animeDataMap;
	vector<int> mapTip;
	int mapTipSizeX;
	int mapTipSizeY;

	void SetupImageMap();
	void SetupImageFilePathMap();
	void SetupAnimeDataMap();
	void AddImageMap(IMAGE_ASSET_NAME assetName);
	void SetupImageMapInstance();
	void Draw(int imageHandle, int posX, int posY);
	void Draw(int imageHandle, int posX, int posY, float scale);
	void Draw(int imageHandle, VECTOR pos, float scale);
	bool CheckConnotationCharacterImageMap(int index);
	bool CheckConnotationBaseImageMap(IMAGE_ASSET_NAME assetName);
	int  GetSizeHalfImageX(int imageIndex);
	int  GetSizeHalfImageY(int imageIndex);
	void CheckNumAndSize(int imageHandle, int* numX, int* numY, int* sizeX, int* sizeY);

};

#endif