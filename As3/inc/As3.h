/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    As3.h
-----------------------------------------------------------------------------
*/
#ifndef __As3_h_
#define __As3_h_

#include "BaseApplication.h"
#include "EntityMgr.h"
#include <string>
#include <stdlib.h>
#include <time.h>

class As3 : public BaseApplication
{
public:
	As3(void);
	~As3(void);

protected:
	virtual void createScene(void);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
	void MakeGround(void);
	void MakeSky(void);
	void MakeEnts(void);

private:
	void UpdateCamera(const Ogre::FrameEvent& fe);
	void UpdateSelectedNode(const Ogre::FrameEvent& fe);

	int surfaceHeight = 0;
	EntityMgr* entityMgr;
	Ogre::SceneNode* cameraNode;
	Ogre::Vector3 velocity = Ogre::Vector3::ZERO;
	float speed = 0;
	float heading = 0;

};

#endif // #ifndef __As3_h_
