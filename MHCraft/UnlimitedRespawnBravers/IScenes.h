#ifndef _SCENEMANAGER_ISCENES_H_
#define _SCENEMANAGER_ISCENES_H_

#include "GSystem.h"

class IScenes
{
public:
	IScenes(){}
	~IScenes(){}

	virtual void				Initialize(SceneMediateData sceneData)= 0;
	virtual SceneMediateData	Update()					= 0;
	virtual void				Draw()						= 0;
	virtual void				Finalize()					= 0;

protected:

private:
};


#endif