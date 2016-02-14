#ifndef TEXT_LOADER
#define TEXT_LOADER

#include<fstream>
#include<string>
#include<functional>
#include<vector>

/*
1�̃t�@�C����ǂݍ��ނ̂ɂ��̃N���X�̃C���X�^���X���P�쐬����B
�p�r��1�̃X�e�[�W�ɂ�1��������B
*/

class TextLoader
{
public:
	TextLoader();
	~TextLoader();

	void LoadDate(std::string path);

	void YXEach(std::function<void (int,int)> Action);

	std::vector<std::vector<int>> GetDate();


private:
	std::vector<std::vector<int>> outPut;

};



#endif