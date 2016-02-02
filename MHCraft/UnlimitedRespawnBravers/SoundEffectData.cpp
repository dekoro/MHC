#include"SoundEffectData.h"

SoundEffectData::SoundEffectData(char *fileName){
	LoadData(fileName);

}
SoundEffectData::~SoundEffectData(){

}
void SoundEffectData::LoadData(char *fileName){
	SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMNOPRESS);
	LoadData(fileName);
}

