#include "MusicData.h"

MusicData::MusicData(char *fileName){
	LoadData(fileName);
}

MusicData::~MusicData(){

}

void MusicData::LoadData(char *fileName){
	SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
	LoadData(fileName);
}