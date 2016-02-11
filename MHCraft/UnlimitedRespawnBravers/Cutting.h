#ifndef CUTTING
#define CUTTING

#include"BaseEffect.h"
#include"e_Directon.h"

class Cutting : public BaseEffect
{
public:
	Cutting(e_CutDirection e_Dir);
	~Cutting();

	void SetSlope(VECTOR);//アップキャストして使ってください
	
private:
	void ConstSet()override;//シェーダーに定数セット

	FLOAT4 slope;//線の傾き

};

#endif


