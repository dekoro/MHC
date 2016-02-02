#include"TextureMapping.h"
#include<DxLib.h>

TextureMapping::TextureMapping() : BaseEffect(LoadPixelShader("Shader/PSTextureMapping.pso"))
{
}

TextureMapping::~TextureMapping()
{
}
