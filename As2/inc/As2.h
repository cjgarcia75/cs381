/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    As2.h
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
	  Tutorial Framework
	  http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#ifndef __As2_h_
#define __As2_h_

#include "BaseApplication.h"
#include <string>
#include <stdlib.h>
#include <time.h>

class As2 : public BaseApplication
{
public:
	As2(void);
	virtual ~As2(void);

protected:
	virtual void createScene(void);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
	void MakeGround(void);
	void MakeSky(void);
	void MakeEnts(void);

private:
	bool processUnbufferedInput(const Ogre::FrameEvent& fe);
	void UpdateCamera(const Ogre::FrameEvent& fe);
	void UpdateSelectedNode(const Ogre::FrameEvent& fe);

	int surfaceHeight = 0;
	EntityMgr* entityMgr;
	Ogre::SceneNode* cameraNode;

};

#endif // #ifndef __As2_h_
