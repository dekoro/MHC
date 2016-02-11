#include"Cutting.h"
#include<assert.h>
#include<DxLib.h>

Cutting::Cutting(e_CutDirection e_Dir)
{
	switch (e_Dir)
	{
	case e_Right:
	BaseEffect :
		BaseEffect::BaseEffect(LoadPixelShader("Shader/PSCutRight.pso"));
		break;
	case e_Left:
		BaseEffect::BaseEffect(LoadPixelShader("Shader/PSCutLeft.pso"));
		break;
	}

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

//x ü‚Ì‰¡,y ü‚Ì‚‚³,zŒX‚«
void Cutting::SetSlope(VECTOR slope)
{
	this->slope.y = slope.y;

	this->slope.x = slope.x;

	this->slope.z = slope.z;
}