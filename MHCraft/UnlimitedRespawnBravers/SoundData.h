#ifndef _DATAMANAGER_SOUNDDATA_H_
#define _DATAMANAGER_SOUNDDATA_H_
#include "GSystemHub.h"

class SoundData{
public:
	SoundData(char* fileName, bool isMusic = false);
	~SoundData();
	int GetDataHandle();
	bool CheckInportedDataHandle();
	bool GetIsMusic();

private:
	int dataHandle;
	bool isMusic;
	void LoadData(char* fileName, bool isMusic);
};


#endif
