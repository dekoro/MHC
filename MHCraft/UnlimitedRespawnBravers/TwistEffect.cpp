#include"TwistEffect.h"
#include<DxLib.h>

TwistEffect::TwistEffect() :BaseEffect(LoadPixelShader("Content/Shader/TwistShader.pso"))
{
}

TwistEffect::~TwistEffect()
{
}

void TwistEffect::ConstantShader()
{
	
}

void TwistEffect::Rendering(std::function<void()> Draw)
{
	BaseEffect::Rendering(Draw);
}

