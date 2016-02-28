#ifndef _CHARACTER_DAMAGEAREA_IHITTABLE_H_
#define _CHARACTER_DAMAGEAREA_IHITTABLE_H_

class IHittable
{
public:
	IHittable(){}
	~IHittable(){}

	virtual void HitFunction() = 0;
private:
};

#endif // !_CHARACTER_DAMAGEAREA_IHITTABLE_H_






