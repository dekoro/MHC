#include"ErrorCheck.h"

bool CanNomal(VECTOR vec)
{
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
	{
		return false;
	}

	return true;
}
