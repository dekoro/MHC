#ifndef TEXTURE_MAPPING
#define TEXTURE_MAPPING

#include"BaseEffect.h"


class TextureMapping : public BaseEffect
{
public:
	TextureMapping();
	~TextureMapping();

	void Initialize();

	void SetRevaerse(bool b);

private:
	void ConstSet()override;

private:
	bool isReverse;

};


#endif