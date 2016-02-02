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
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 1, TRUE, GetColor(0, 255, 255), 0);	//”wŒi
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 2, TRUE, colorList.colorArmer, 255);	//ŠZ
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 3, TRUE, colorList.colorSkin, 255);	//”§
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 4, TRUE, colorList.colorHair, 255);	//”¯
		GraphFilter(dataHandle[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 5, TRUE, colorList.colorFrame);		//ƒtƒŒ[ƒ€
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
		Debug::Alert("ƒtƒ@ƒCƒ‹‚Ì“Ç‚Ý‚±‚Ý‚ÉŽ¸”s‚µ‚Ü‚µ‚½B");
	}

	for (int i = 0; i < ANIME_FRAME_NUM; i++){
		if (chImageHandle[i] > 0){ continue; }
		chImageHandle[i] = 0;
	}
}

*/


