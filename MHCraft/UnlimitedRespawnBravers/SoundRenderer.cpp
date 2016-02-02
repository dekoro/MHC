#include "SoundRenderer.h"

SoundRenderer::SoundRenderer(){
	Initialize();
}

SoundRenderer::~SoundRenderer(){
	ClearSoundMap();
}

void SoundRenderer::Initialize(){
	AddSoundMap(Music_Title_BGM				, "./Resource/Title_BGM.mp3"			, true);
	AddSoundMap(Music_GameMain_BGM_Normal	, "./Resource/GameMain_BGM_normal.mp3"	, true);
	AddSoundMap(Music_GameMain_BGM_BOSS		, "./Resource/GameMain_BGM_boss.mp3"	, true);
	
	AddSoundMap(SE_Decision					, "./Resource/SE_Decision.mp3"		, false);
	AddSoundMap(SE_Attack					, "./Resource/SE_Attack.mp3"		, false);
	AddSoundMap(SE_Damage					, "./Resource/SE_Damage.mp3"		, false);
	AddSoundMap(SE_Kill						, "./Resource/SE_Kill.mp3"			, false);
	AddSoundMap(SE_KillBoss					, "./Resource/SE_KillBoss.mp3"		, false);
	AddSoundMap(SE_Dead						, "./Resource/SE_Dead.mp3"			, false);
	AddSoundMap(SE_Drop						, "./Resource/SE_Drop.wav"			, false);
	AddSoundMap(SE_Get						, "./Resource/SE_Get.wav"			, false);
}		

void SoundRenderer::Play(SoundAsset assetName){
	FAST_RETURN_VOID(!soundMap[assetName]->CheckInportedDataHandle());
	if (soundMap[assetName]->GetIsMusic()){
		FAST_RETURN_VOID(IsPlay(assetName));
		OtherAllStop(assetName);
	}	
	int soundHandle = soundMap[assetName]->GetDataHandle();
	int playType = (soundMap[assetName]->GetIsMusic())? DX_PLAYTYPE_LOOP: DX_PLAYTYPE_BACK;
	Stop(assetName);
	PlaySoundMem(soundHandle,playType);
}

void SoundRenderer::Stop(SoundAsset assetName){
	FAST_RETURN_VOID(!IsPlay(assetName));
	StopSoundMem(soundMap[assetName]->GetDataHandle());
}

bool SoundRenderer::IsPlay(SoundAsset assetName){
	return (CheckSoundMem(soundMap[assetName]->GetDataHandle()) == 1);
}

void SoundRenderer::AddSoundMap(SoundAsset assetName, char* fileName, bool isMusic = false){
	soundMap.insert(map<SoundAsset, SoundData*>::value_type(assetName, new SoundData(fileName, isMusic)));
	if (isMusic){
		ChangeVolumeSoundMem(120, soundMap[assetName]->GetDataHandle());
	}
}

void SoundRenderer::ClearSoundMap(){
	SAFE_DELETE(soundMap[Music_Title_BGM]);
	SAFE_DELETE(soundMap[Music_GameMain_BGM_Normal]);
	SAFE_DELETE(soundMap[Music_GameMain_BGM_BOSS]);
}

void SoundRenderer::OtherAllStop(SoundAsset assetName){
	if (!soundMap[assetName]->GetIsMusic()){ return; }
	for (int i=0; i < SOUND_ASSET_NUM; i++){
		SoundAsset stopAsset = (SoundAsset)i;
		if (stopAsset == assetName){ continue; }
		Stop(stopAsset);
	}
}


