#ifndef ERROR_CHECK
#define ERROR_CHECK

#include<unordered_map>
#include<assert.h>
#include<DxLib.h>

/*
ここの関数はアサートを内部で使用している。
ここの関数を使う時は#if _DEBUGを使うようにする
*/

bool  CanNomal(VECTOR vec);

//マップにすでに登録されているか
template <typename KEY, typename ELEMENT>
void CheckAlreadyThere(KEY key, std::unordered_map<KEY, ELEMENT> map)
{
	for (auto element : map)
	{
		assert(element.first != key && "すでにキーが登録されています");
	}
}

//マップにキーが存在するか
template <typename KEY, typename ELEMENT>
void CheckRegiserKey(KEY key, std::unordered_map<KEY, ELEMENT> map)
{
	assert(map.find(key) != map.end() && "キーが登録されていません");
}

template <typename T>
void IsNullptr(T* t)
{/*
	if (t == nullptr)
	{
		assert();
	}*/
}



#endif