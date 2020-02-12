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
	virtual void createCamera(void);
    virtual void createViewports(void);
	virtual void createScene(void);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

private:
	bool processUnbufferedInput(const Ogre::FrameEvent& fe);

	bool bb = true;
	Ogre::Vector3 velocity = Ogre::Vector3::ZERO;
	Ogre::Vector3 initCamPos = Ogre::Vector3(0, 900, 3000);
	Ogre::Entity* cubeEnts[100];
	Ogre::SceneNode* cubes[100];
	int selectedCube = 0;
	int posNeg[2] = {-1, 1};
	bool tracking = false;
	bool trackShip = false;
	bool controlShip = false;

};

#endif // #ifndef __As2_h_
