/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
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

#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
	// create your scene here :)
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

	// Ground
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			plane, 1500, 1500, 20 , 20 , true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	groundEntity->setCastShadows(false);
	groundEntity->setMaterialName("Examples/Rockwall");

	// Ogre 1
	Ogre::Entity* ogreEntity = mSceneMgr->createEntity("robot.mesh");
	ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreNode->showBoundingBox(true);
	ogreNode->attachObject(ogreEntity);

	// Ogre 2
	Ogre::Entity* ogreEntity2 = mSceneMgr->createEntity("robot.mesh");
	ogreNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreNode2->setPosition(-100, 0, 0);
	ogreNode2->yaw(Ogre::Degree(90));
	ogreNode2->showBoundingBox(true);
	ogreNode2->attachObject(ogreEntity2);

	Ogre::Entity* ogreEntity3 = mSceneMgr->createEntity("robot.mesh");
	ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreNode3->setPosition(0, 100, 0);
	ogreNode3->setScale(2, 1, 2);
	ogreNode3->yaw(Ogre::Degree(180));
	ogreNode3->showBoundingBox(true);
	ogreNode3->attachObject(ogreEntity3);

	Ogre::Entity* ogreEntity4 = mSceneMgr->createEntity("robot.mesh");
	ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreNode4->setPosition(100, 0, 0);
	ogreNode4->yaw(Ogre::Degree(-90));
	ogreNode4->showBoundingBox(true);
	ogreNode4->attachObject(ogreEntity4);


	Ogre::Light* light = mSceneMgr->createLight("MainLight");
	light->setPosition(20, 80, 50);

	mCamera->setPosition(0, 120, 500);
	mCamera->lookAt(Ogre::Vector3(0, 0, -300));

}

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#include "macUtils.h"
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
	extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
		int main(int argc, char *argv[])
#endif
		{
			// Create application object
			TutorialApplication app;

			try {
				app.go();
			} catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
				MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
				std::cerr << "An exception has occurred: " <<
					e.getFullDescription().c_str() << std::endl;
#endif
			}

			return 0;
		}

#ifdef __cplusplus
	}
#endif
