#ifndef ANIMATION
#define ANIMATION

#include<unordered_map>
#include<vector>
#include<string>

class Animation
{
public:
	Animation();
	~Animation();

	void Initialize();

	void AddMotion(std::string motionName,std::vector<int > motions);

	int GetMotion(std::string motionName);

	void Update();

	void ChangeMotion(std::string name);

	

private:
	std::unordered_map < std::string , std::vector<int >> motions;//アニメーションのグラフィックハンドル

	std::vector<int> currentMotion;

	int motionCount;

	std::string currentName;
};

#endif