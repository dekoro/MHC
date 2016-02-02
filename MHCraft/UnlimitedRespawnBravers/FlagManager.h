#ifndef _GSYSTEM_FLAGMANAGER_H_
#define _GSYSTEM_FLAGMANAGER_H_

#include "SystemHub.h"


template<typename T>
class FlagManager{
public:
	FlagManager();
	~FlagManager();

	static bool			GetFlag		 (T* flags, int index);
	static T			GetAllFlags	 (T* flags);
	static void			SetFlag		 (T* flags, int index, bool set);

	static void			UpperFlag	 (T* flags);
	static void			DownerFlag	 (T* flags);
	static void			ReservalFlag (T* flags);
	static void			PrintFlag	 ();
private:
	bool CheckValidIndex(int index);
	T	 ChangeIndexToValue(int index);
};


#endif
