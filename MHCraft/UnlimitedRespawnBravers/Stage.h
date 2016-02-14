#ifndef STAGE
#define STAGE

#include<functional>
#include<vector>

class Stage
{
public:
	Stage(std::vector <std::vector<int>> date);
	~Stage();

	void Draw();

private:
	void mapEach(std::function<void(int, int)> Action);

	std::vector <std::vector<int>> mapDate;
};

#endif