#ifndef CUTTING
#define CUTTING

#include"BaseEffect.h"

class Cutting : public BaseEffect
{
public:
	Cutting();
	~Cutting();

	void SetSlope(VECTOR);//アップキャストして使ってください
	
private:
	void ConstSet()override;//シェーダーに定数セット

	FLOAT4 slope;//線の傾き

};

#endif


