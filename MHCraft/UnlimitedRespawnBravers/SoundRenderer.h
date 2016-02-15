#ifndef _DEVICE_RENDERER_SOUNDRENDERER_H_
#define _DEVICE_RENDERER_SOUNDRENDERER_H_
#include "SystemHub.h"
#include "SoundData.h"

#define SOUND_ASSET_NUM 3
enum SoundAsset{
	Music_Title_BGM,
	Music_GameMain_BGM_Normal,
	Music_GameMain_BGM_BOSS,
	Music_GameMain_Lose,
	Music_GameMain_Win,

	SE_Decision,
	SE_Attack,
	SE_Damage,
	SE_Kill,
	SE_KillBoss,
	SE_Dead,
	SE_Drop,
	SE_Get
};


class SoundRenderer
{
public:
	SoundRenderer();
	~SoundRenderer();

	void Initialize();
	void Play(SoundAsset assetName);
	void Stop(SoundAsset assetName);
	bool IsPlay(SoundAsset assetName);
private:
	std::map<SoundAsset, char*> soundPathMap;
	std::map<SoundAsset, SoundData*> soundMap;

	void AddSoundMap(SoundAsset assetName, char* fileName, bool isMusic);
	void ClearSoundMap();
	void OtherAllStop(SoundAsset assetName);
};

#endif











