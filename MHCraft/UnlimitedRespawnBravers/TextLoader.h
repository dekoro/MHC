#ifndef TEXT_LOADER
#define TEXT_LOADER

#include<fstream>
#include<string>
#include<functional>
#include<vector>

/*
1つのファイルを読み込むのにこのクラスのインスタンスを１つ作成する。
用途は1つのステージにつき1つ持たせる。
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