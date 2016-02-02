#include "CharacterImageData.h"


void CharacterImageData::SetPlayerFrameColor(unsigned int color){
	
}
/*
int CharacterImageData::GetImageHandle(){
	return chImageHandle[nowType*animeData.XNum + nowFrame];
}
*/
//---private---

void CharacterImageData::ChangePlayerColor(PlayerColorList colorList){
	for (int i = 0; i < ANIME_FRAME_NUM; i++){
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 1, TRUE, GetColor(0, 255, 255), 0);	//背景
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 2, TRUE, colorList.colorArmer, 255);	//鎧
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 3, TRUE, colorList.colorSkin, 255);	//肌
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 4, TRUE, colorList.colorHair, 255);	//髪
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 5, TRUE, colorList.colorFrame);		//フレーム
	}
}

/*
void CharacterImageData::LoadData(char* filePath){
	int resoultLoad;
	resoultLoad = LoadDivGraph(filePath, animeData.GetFrameAllNum()
							 , animeData.XNum, animeData.typeNum
							 , animeData.oneSizeX, animeData.oneSizeY
							 , chImageHandle);
	if (resoultLoad == -1){
		Debug::Alert("ファイルの読みこみに失敗しました。");
	}

	for (int i = 0; i < ANIME_FRAME_NUM; i++){
		if (chImageHandle[i] > 0){ continue; }
		chImageHandle[i] = 0;
	}
}

*/


