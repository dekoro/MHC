#ifndef ANIMATION
#define ANIMATION

#include<unordered_map>
#include<vector>
#include<string>

enum e_Motion
{
	e_STAND,//��C
	e_WALK,//����
	e_ATTACK,//�U��
};

struct Anime
{
	std::vector<int> motions;
	bool isLoop;
	e_Motion currentName;
};



class Animation
{
public:
	Animation(int intarval);
	~Animation();

	void Initialize();

	void AddMotion(e_Motion motionName, std::vector<int> motions, bool isLoop);

	int GetMotion();

	void Update();

	void ChangeMotion(e_Motion name);

	bool IsEnd();

private:
	std::unordered_map < e_Motion , Anime> motions;//�A�j���[�V�����̃O���t�B�b�N�n���h��

	Anime currentMotion;

	int motionCount;

	const int intarval;

	int intarvalCount;

	bool isEnd;
};

#endif