/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    As2.cpp
-----------------------------------------------------------------------------
*/

#include "As2.h"

//-------------------------------------------------------------------------------------
As2::As2(void)
{
}
//-------------------------------------------------------------------------------------
As2::~As2(void)
{
}

//-------------------------------------------------------------------------------------
void As2::createCamera()
{
	mCamera = mSceneMgr->createCamera("PlayerCam");
	mCamera->setPosition(initCamPos);
	mCamera->lookAt(Ogre::Vector3(0, 900, 0));
	mCamera->setNearClipDistance(5);

	mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}

void As2::createViewports()
{
	Ogre::Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
	mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}

void As2::createScene(void)
{
	// create your scene here :)
	int surfaceHeight = -100;

	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.25, 0.25, 0.25));

	// light
	Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
	pointLight->setType(Ogre::Light::LT_POINT);
	pointLight->setPosition(250, 150, 250);
	pointLight->setDiffuseColour(Ogre::ColourValue::White);
	pointLight->setSpecularColour(Ogre::ColourValue::White);

	// cubes
	int x = -900;
	int y = 0;

	for(int i = 0; i < 100; i++)
	{
		cubeEnts[i] = mSceneMgr->createEntity("cube.mesh");

		std::string temp = "CubeNode" + std::to_string(i);

		cubes[i] = mSceneMgr->getRootSceneNode()->createChildSceneNode(temp.c_str());
		cubes[i]->setPosition(x, y, 0);
		cubes[i]->attachObject(cubeEnts[i]);
		cubeEnts[i]->setMaterialName("Examples/Rockwall");

		x += 200;
		if(x > 900)
			x = -900;

		if(i > 0 && x == -900)
			y += 200;
	}

	// ship
	Ogre::Entity* shipEntity = mSceneMgr->createEntity("ship.mesh");
	Ogre::SceneNode* shipNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("shipNode");
	shipNode->setPosition(0, surfaceHeight, 0);
	shipNode->yaw(Ogre::Degree(90));
	shipNode->attachObject(shipEntity);

	// water
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	Ogre::MeshManager::getSingleton().createPlane("ground",
			Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			plane,
			15000, 15000, 20, 20,
			true,
			1, 5, 5,
			Ogre::Vector3::UNIT_Z);
	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	Ogre::SceneNode* groundNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("GroundNode");
	groundNode->attachObject(groundEntity);
	groundNode->setPosition(0, surfaceHeight, 0);
	groundEntity->setCastShadows(false);
	groundEntity->setMaterialName("Ocean2_Cg");

	// sky box
	mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");
}

bool As2::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
	mKeyboard->capture();

	return(processUnbufferedInput(fe));
}

bool As2::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
	static bool mouseDownLastFrame = false;
	static bool tabDownLastFrame = false;
	static bool cDownLastFrame = false;
	static bool vDownLastFrame = false;
	static Ogre::Real rotate = 0.03;
	static Ogre::Real shipRot = 0.008;
	static Ogre::Real move = 2;
	static Ogre::Real shipMove = 50;
	static Ogre::Real moveCam = 300;
	bool camMoving = true;

	srand(time(NULL));

	bool leftMouseDown = mMouse->getMouseState().buttonDown(OIS::MB_Left);
	bool tabDown = mKeyboard->isKeyDown(OIS::KC_TAB);
	bool cDown = mKeyboard->isKeyDown(OIS::KC_C);
	bool vDown = mKeyboard->isKeyDown(OIS::KC_V);

	if(leftMouseDown && !mouseDownLastFrame)
	{
		Ogre::Light* light = mSceneMgr->getLight("PointLight"); // @suppress("Invalid arguments")
		light->setVisible(!light->isVisible());
	}

	mouseDownLastFrame = leftMouseDown;
	Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

	// select cube
	if(tabDown && !tabDownLastFrame)
	{
		selectedCube++;
		if(selectedCube == 100)
		{
			cubes[99]->showBoundingBox(false);
			selectedCube = 0;
		}

		if(selectedCube > 0)
			cubes[selectedCube - 1]->showBoundingBox(false);
	}
	tabDownLastFrame = tabDown;

	cubes[selectedCube]->showBoundingBox(true);

	Ogre::Vector3 oldPos = cubes[selectedCube]->getPosition();

	if(!controlShip)
	{
		// stop cube
		if(mKeyboard->isKeyDown(OIS::KC_SPACE))
		{
			velocity.x = 0;
			velocity.y = 0;
			velocity.z = 0;
		}
		// move cube forward
		if(mKeyboard->isKeyDown(OIS::KC_I) || mKeyboard->isKeyDown(OIS::KC_NUMPAD8))
			velocity.z -= move;
		// move cube back
		if(mKeyboard->isKeyDown(OIS::KC_K) || mKeyboard->isKeyDown(OIS::KC_NUMPAD2))
			velocity.z += move;
		// move cube down
		if(mKeyboard->isKeyDown(OIS::KC_U) || mKeyboard->isKeyDown(OIS::KC_PGDOWN))
			velocity.y -= move;
		// move cube up
		if(mKeyboard->isKeyDown(OIS::KC_O) || mKeyboard->isKeyDown(OIS::KC_PGUP))
			velocity.y += move;
		// move cube left
		if(mKeyboard->isKeyDown(OIS::KC_J) || mKeyboard->isKeyDown(OIS::KC_NUMPAD4))
			velocity.x -= move;
		// move cube right
		if(mKeyboard->isKeyDown(OIS::KC_L) || mKeyboard->isKeyDown(OIS::KC_NUMPAD6))
			velocity.x += move;
	}
	else
	{
		// move ship forward
		if(mKeyboard->isKeyDown(OIS::KC_I) || mKeyboard->isKeyDown(OIS::KC_NUMPAD8))
			dirVec.x += shipMove;
		// move ship back
		if(mKeyboard->isKeyDown(OIS::KC_K) || mKeyboard->isKeyDown(OIS::KC_NUMPAD2))
			dirVec.x -= shipMove;
		// move ship left
		if(mKeyboard->isKeyDown(OIS::KC_J) || mKeyboard->isKeyDown(OIS::KC_NUMPAD4))
			mSceneMgr->getSceneNode("shipNode")->yaw(Ogre::Degree(5 * shipRot));
		// move ship right
		if(mKeyboard->isKeyDown(OIS::KC_L) || mKeyboard->isKeyDown(OIS::KC_NUMPAD6))
			mSceneMgr->getSceneNode("shipNode")->yaw(Ogre::Degree(-5 * shipRot));

		mSceneMgr->getSceneNode("shipNode")->translate(
				dirVec * fe.timeSinceLastFrame,
				Ogre::Node::TS_LOCAL);
	}

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

	// change camera
	if(cDown && !cDownLastFrame)
	{
		if(!tracking)
			tracking = true;
		else
		{
			tracking = false;
			camMoving = false;
		}
	}

	cDownLastFrame = cDown;

	if(tracking)
	{
		Ogre::Vector3 cubePos = cubes[selectedCube]->getPosition();
		mCamera->setPosition(cubePos + Ogre::Vector3(0, 100, 500));
		mCamera->lookAt(cubePos);
	}
	else if(!tracking && mCamera->getPosition() != initCamPos && !camMoving)
	{
		mCamera->setPosition(initCamPos);
		mCamera->lookAt(Ogre::Vector3(0, 900, 0));
		camMoving = true;
	}

	// follow ship
	if(vDown && !vDownLastFrame)
	{
		if(!trackShip)
		{
			trackShip = true;
			controlShip = true;
		}
		else
		{
			trackShip = false;
			controlShip = false;
			camMoving = false;
		}
	}

	vDownLastFrame = vDown;

	if(trackShip)
	{
		Ogre::Vector3 shipPos = mSceneMgr->getSceneNode("shipNode")->getPosition();
		mCamera->setPosition(shipPos + Ogre::Vector3(0, 10, 30));
		mCamera->lookAt(shipPos);
	}
	else if(!trackShip && mCamera->getPosition() != initCamPos && !camMoving)
	{
		mCamera->setPosition(initCamPos);
		mCamera->lookAt(Ogre::Vector3(0, 900, 0));
		camMoving = true;
	}

	// quit
	if(mKeyboard->isKeyDown(OIS::KC_Q))
		return false;

	cubes[selectedCube]->yaw(Ogre::Degree((rand() % 5 + 1) * rotate * posNeg[rand() % 2]));
	cubes[selectedCube]->pitch(Ogre::Degree((rand() % 5 + 1) * rotate * posNeg[rand() % 2]));
	cubes[selectedCube]->roll(Ogre::Degree((rand() % 5 + 1) * rotate * posNeg[rand() % 2]));

	cubes[selectedCube]->setPosition(oldPos + (velocity * fe.timeSinceLastFrame));

	mCamera->moveRelative(dirVec * fe.timeSinceLastFrame);

	return true;
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
			As2 app;

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
