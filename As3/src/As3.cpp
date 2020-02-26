/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    As3.cpp
-----------------------------------------------------------------------------
*/

#include <As3.h>

//-------------------------------------------------------------------------------------
As3::As3(void)
{
}
//-------------------------------------------------------------------------------------
As3::~As3(void)
{
}

//-------------------------------------------------------------------------------------
void As3::createScene(void)
{
	// create your scene here :)
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

	mCamera->lookAt(Ogre::Vector3(0, 0, 0));

	Ogre::Light* light = mSceneMgr->createLight("MainLight");
	light->setPosition(20.0, 80.0, 50.0);

	// light
//	Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
//	pointLight->setType(Ogre::Light::LT_POINT);
//	pointLight->setPosition(250, 150, 250);
//	pointLight->setDiffuseColour(Ogre::ColourValue::White);
//	pointLight->setSpecularColour(Ogre::ColourValue::White);

	// fixed point to see motion
	Ogre::Entity* ogreEntityFixed = mSceneMgr->createEntity("robot.mesh");
	Ogre::SceneNode* sceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0, 100, -200));
	sceneNode->attachObject(ogreEntityFixed);
	sceneNode->showBoundingBox(true);

	cameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	cameraNode->setPosition(0, 200, 500);
	cameraNode->attachObject(mCamera);

	// water
	MakeGround();

	// sky box
	MakeSky();

	entityMgr = new EntityMgr(mSceneMgr);

	MakeEnts();
}

bool As3::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
	mKeyboard->capture();
	if(mKeyboard->isKeyDown(OIS::KC_Q))
		return false;

	UpdateCamera(fe);

	UpdateSelectedNode(fe);

	entityMgr->Tick(fe.timeSinceLastFrame);

	return(true);
}

void As3::MakeGround(void)
{
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, surfaceHeight);

	Ogre::MeshManager::getSingleton().createPlane(
			"ground",
			Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			plane,
			15000, 15000, 20, 20,
			true,
			1, 5, 5,
			Ogre::Vector3::UNIT_Z);

	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	groundEntity->setCastShadows(false);
	groundEntity->setMaterialName("Ocean2_Cg");
}

void As3::MakeSky(void)
{
	mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");
}

void As3::MakeEnts(void)
{
	Ogre::Vector3 pos = Ogre::Vector3(-400, 0, 0);

	entityMgr->CreateEntity(mSceneMgr, 0, "ddg51.mesh", pos);

	pos.x += 200;

	entityMgr->CreateEntity(mSceneMgr, 1, "cvn68.mesh", pos);

	pos.x += 200;

	entityMgr->CreateEntity(mSceneMgr, 2, "cigarette.mesh", pos);

	pos.x += 200;

	entityMgr->CreateEntity(mSceneMgr, 3, "sleek.mesh", pos);

	pos.x += 200;

	entityMgr->CreateEntity(mSceneMgr, 4, "alienship.mesh", pos);
}

void As3::UpdateCamera(const Ogre::FrameEvent& fe)
{
	static Ogre::Real moveCam = 300;
	Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

	// move camera forward
	if(mKeyboard->isKeyDown(OIS::KC_W))
		dirVec.z -= moveCam;
	// move camera back
	if(mKeyboard->isKeyDown(OIS::KC_S))
		dirVec.z += moveCam;
	// move camera up
	if(mKeyboard->isKeyDown(OIS::KC_E))
		dirVec.y += moveCam;
	// move camera down
	if(mKeyboard->isKeyDown(OIS::KC_F))
		dirVec.y -= moveCam;
	// move camera right
	if(mKeyboard->isKeyDown(OIS::KC_D))
		dirVec.x += moveCam;
	// move camera left
	if(mKeyboard->isKeyDown(OIS::KC_A))
		dirVec.x -= moveCam;

	if(mKeyboard->isKeyDown(OIS::KC_LSHIFT) && mKeyboard->isKeyDown(OIS::KC_A))
		cameraNode->yaw(Ogre::Degree(0.05));
	if(mKeyboard->isKeyDown(OIS::KC_LSHIFT) && mKeyboard->isKeyDown(OIS::KC_D))
		cameraNode->yaw(Ogre::Degree(-0.05));

	cameraNode->translate(dirVec * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
}

void As3::UpdateSelectedNode(const Ogre::FrameEvent& fe)
{
	static float move = 1;
	static float rot = 2;

	static bool tabDownLastFrame = false;
	bool tabDown = mKeyboard->isKeyDown(OIS::KC_TAB);

	if(tabDown && !tabDownLastFrame)
	{
		entityMgr->SelectNextEnt();
		speed = entityMgr->getSpeed();
		heading = entityMgr->getHeading();
	}

	tabDownLastFrame = tabDown;

	// accelerate
	if(mKeyboard->isKeyDown(OIS::KC_I) || mKeyboard->isKeyDown(OIS::KC_NUMPAD8))
	{
		speed += move;
		if(speed > entityMgr->getMaxSpeed())
			speed = entityMgr->getMaxSpeed();
	}
	// decelerate
	if(mKeyboard->isKeyDown(OIS::KC_K) || mKeyboard->isKeyDown(OIS::KC_NUMPAD2))
	{
		speed -= move;
		if(speed < 0)
			speed = 0;
	}

	// turn left
	if(mKeyboard->isKeyDown(OIS::KC_J) || mKeyboard->isKeyDown(OIS::KC_NUMPAD4))
	{
		heading -= rot;
		if(heading < 0)
			heading = 360;
	}

	// turn right
	if(mKeyboard->isKeyDown(OIS::KC_L) || mKeyboard->isKeyDown(OIS::KC_NUMPAD6))
	{
		heading += rot;
		if(heading > 360)
			heading = 0;
	}

	entityMgr->ChangeSpeed(speed);
	entityMgr->ChangeHeading(heading);
//	std::cout << speed << "\n" << heading << "\n";
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
			As3 app;

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
