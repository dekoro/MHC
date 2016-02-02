#include "FlagManager.h"

template<typename T = unsigned int>
FlagManager<T>::FlagManager(){
	flag = 0;
}

template<typename T = unsigned int>
FlagManager<T>::~FlagManager(){

}

template<typename T = unsigned int>
 bool FlagManager<T>::GetFlag(T *flags, int index){

}

 template<typename T = unsigned int>
 static T FlagManager<T>::GetAllFlags(T* flags){
	 return 0;
 }

template<typename T = unsigned int>
 void FlagManager<T>::SetFlag(T *flags, int index, bool set){
	if (!CheckValidIndex(index)){ DEBUG_ERROR_RETURN("xx",0); }
	T indexNum = (T)pow(2.0, index);

	if (set){
		UpperFlg(indexNum);
		return;
	}
	DownerFlg(indexNum);
}

template<typename T = unsigned int>
 void FlagManager<T>::UpperFlag(T *flags){
//	flg |= flglist;
}

template<typename T = unsigned int>
 void FlagManager<T>::DownerFlag(T *flags){
//	flg &= ~flglist;
}
template<typename T = unsigned int>
 void FlagManager<T>::ReservalFlag(T *flags){

}
template<typename T = unsigned int>
 bool FlagManager<T>::CheckValidIndex(int index){
	return (0 <= index && index < sizeof(T)*8);
}

template<typename T = unsigned int>
 T FlagManager<T>::ChangeIndexToValue(int index){
	if (!CheckValidIndex(index)){ DEBUG_ERROR_RETURN("FLAG_INDEXílÇ™ïsê≥Ç≈Ç∑", 0); }
	return (T)pow(2, index);
}

