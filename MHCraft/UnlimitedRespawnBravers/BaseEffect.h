#ifndef BASE_EFFECT
#define BASE_EFFECT

#include<functional>

class BaseEffect
{
public:
	BaseEffect(int psHundle = 0,int vsHundle = 0);
	virtual ~BaseEffect();

	virtual void Rendering(std::function<void()> Draw);

protected:
	//シェーダーに定数をセットする
	virtual void ConstantShader(){};

protected:
	int ps;
	int vs;

};

#endif