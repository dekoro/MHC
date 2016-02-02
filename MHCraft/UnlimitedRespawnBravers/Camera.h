#ifndef _GSYSTEM_CAMERA_H_
#define _GSYSTEM_CAMERA_H_

#include "SystemHub.h"

class Camera
{
public:
	~Camera();

	Camera Instance();

private:
	static Camera instance;

	Camera();

};


#endif // !_GSYSTEM_CAMERA_H_
