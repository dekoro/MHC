#include"Cutting.h"
#include<assert.h>
#include<DxLib.h>

Cutting::Cutting() :BaseEffect(LoadPixelShader("Shader/PSCut.pso"), LoadVertexShader(""))
{
	//xが傾き

	slope.x = 0.0;
	slope.y = 0.0;
	slope.z = 0.0;

}

Cutting::~Cutting()
{
}

void Cutting::ConstSet()
{
	SetSlope(VGet(0.5,0.5,0.7));
	SetPSConstF(0,slope);
}

//x 線の横,y 線の高さ,z傾き
void Cutting::SetSlope(VECTOR slope)
{
	this->slope.y = slope.y;

	this->slope.x = slope.x;

	this->slope.z = slope.z;
}