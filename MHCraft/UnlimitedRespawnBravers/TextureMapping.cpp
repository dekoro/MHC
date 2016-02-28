#include"TextureMapping.h"
#include<DxLib.h>
#include"EffectManager.h"

TextureMapping::TextureMapping() : BaseEffect(EffectManager::GetInstance()->GetEffect("TexMap")){

}

TextureMapping::~TextureMapping(){

}

void TextureMapping::Initialize()
{
	this->isReverse = false;
}

void TextureMapping::SetRevaerse(bool b)
{
	this->isReverse = b;
}

void TextureMapping::ConstSet()
{
	SetPSConstSF(0,isReverse);
}

