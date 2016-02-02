#include "SoundData.h"

SoundData::SoundData(char* fileName, bool isMusic){
	dataHandle = 0;
	LoadData(fileName, isMusic);
}

SoundData::~SoundData(){
	FAST_RETURN_VOID(!CheckInportedDataHandle());
	DeleteSoundMem(dataHandle);
}

int SoundData::GetDataHandle(){
	return dataHandle;
}
bool SoundData::CheckInportedDataHandle(){
	return (dataHandle != NULL);
}

bool SoundData::GetIsMusic(){
	return isMusic;
}
//---protected---


//---private---

void SoundData::LoadData(char* fileName, bool isMusic){
	if (isMusic){ SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE); }
	dataHandle = LoadSoundMem(fileName);
	this->isMusic = isMusic;
}
