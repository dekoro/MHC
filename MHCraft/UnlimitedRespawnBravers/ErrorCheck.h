#ifndef ERROR_CHECK
#define ERROR_CHECK

#include<unordered_map>
#include<assert.h>
#include<DxLib.h>

/*
�����̊֐��̓A�T�[�g������Ŏg�p���Ă���B
�����̊֐����g������#if _DEBUG���g���悤�ɂ���
*/

bool  CanNomal(VECTOR vec);

//�}�b�v�ɂ��łɓo�^����Ă��邩
template <typename KEY, typename ELEMENT>
void CheckAlreadyThere(KEY key, std::unordered_map<KEY, ELEMENT> map)
{
	for (auto element : map)
	{
		assert(element.first != key && "���łɃL�[���o�^����Ă��܂�");
	}
}

//�}�b�v�ɃL�[�����݂��邩
template <typename KEY, typename ELEMENT>
void CheckRegiserKey(KEY key, std::unordered_map<KEY, ELEMENT> map)
{
	assert(map.find(key) != map.end() && "�L�[���o�^����Ă��܂���");
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