#include"TextLoader.h"
#include<assert.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<sstream>


std::vector<int> Split(const std::string &str, char sep)
{
	std::vector<int> v;
	std::stringstream ss(str);
	std::string buffer;
	while (std::getline(ss, buffer, sep))
	{
		v.push_back(atoi(buffer.c_str()));
	}

	return v;
}

//ファイルパス　データの縦の行数
TextLoader::TextLoader()
{

}

TextLoader::~TextLoader()
{

}

void TextLoader::LoadDate(std::string path)
{
	std::fstream ifs(path.c_str());
	std::string str;
	//assert(!ifs.fail());

	int count = 0;

	while (std::getline(ifs, str))//0から順に横のメモリを確保していく
	{
		count++;
	}

	ifs.close();

	ifs = std::fstream(path.c_str());

	this->outPut.resize(count);

	count = 0;

	while (std::getline(ifs, str))//0から順に横のメモリを確保していく
	{
		this->outPut[count++]=Split(str,',');
	}
}


void TextLoader::YXEach(std::function<void(int, int)> Action)
{

}

std::vector<std::vector<int>> TextLoader::GetDate()
{
	return outPut;
}