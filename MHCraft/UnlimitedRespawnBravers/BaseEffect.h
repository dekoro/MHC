#ifndef BASE_EFFECT
#define BASE_EFFECT

#include<functional>
#include<DxLib.h>

/*
シェーダーの管理クラスが各シーンのInitialize部でロードしているため、
このクラスを継承してるクラスも込みで動的に確保してくださいｓ
*/

class BaseEffect
{
public:
	BaseEffect(int psHundle = 0,int vsHundle = 0);
	virtual ~BaseEffect();

	virtual void Rendering(std::function<void()> Draw);


protected:
	virtual void ConstSet(){};//シェーダーに定数セット

protected:
	int ps;
	int vs;

};

#endif