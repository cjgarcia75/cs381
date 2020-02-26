/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    Entity381.cpp
-----------------------------------------------------------------------------
*/

#include "Entity381.h"
#include "Aspect.h"

Entity381::Entity381(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos)
{
//	std::string n = "/assets/" + name;
	fileName = name;
	position = pos;
	velocity = Ogre::Vector3(0, 0, 0);

	ent = mSceneMgr->createEntity(fileName.c_str());
	node = mSceneMgr->getRootSceneNode()->createChildSceneNode(pos);
	node->attachObject(ent);
	node->showBoundingBox(false);

	aspects.clear();
	Physics* phx = new Physics(this);
	aspects.push_back(phx);
	Renderer *rndrr = new Renderer(this);
	aspects.push_back(rndrr);
}

Entity381::~Entity381()
{

}

void Entity381::Tick(float dt)
{
	for(unsigned int i = 0; i < aspects.size(); i++)
	{
		aspects[i]->Tick(dt);
//		std::cout << "Entity tick: " << aspects[i]->entity << "\n";
	}
//	std::cout << speed << "\n" << heading << "\n";
//	std::cout<< "Entity381 dSpeed: " << desiredSpeed << "\nEntity381 dHeading: " << desiredHeading << "\n";
}

void Entity381::setVelocity(Ogre::Vector3 vel)
{
	velocity = vel;
}

void Entity381::setPosition(Ogre::Vector3 pos)
{
	position = pos;
}

Ogre::Vector3 Entity381::getVelocity()
{
	return velocity;
}

Ogre::Vector3 Entity381::getPosition()
{
	return position;
}

Ogre::SceneNode* Entity381::getNode()
{
	return node;
}

void Entity381::ChangeShowBox()
{
	if(node->getShowBoundingBox())
		node->showBoundingBox(false);
	else
		node->showBoundingBox(true);
}

////////////////////////////////////////////////////

Destroyer::Destroyer(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381(mSceneMgr, id, name, pos)
{
	entityName = "Destroyer" + std::to_string(id);
	maxSpeed = 10;
	acceleration = 2;
	turningRate = 2;
}

Destroyer::~Destroyer()
{

}

////////////////////////////////////////////////////

Carrier::Carrier(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381(mSceneMgr, id, name, pos)
{
	entityName = "Carrier" + std::to_string(id);
	maxSpeed = 20;
	acceleration = 2;
	turningRate = 2;
}

Carrier::~Carrier()
{

}

////////////////////////////////////////////////////

Speedboat::Speedboat(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381(mSceneMgr, id, name, pos)
{
	entityName = "Speedboat" + std::to_string(id);
	maxSpeed = 15;
	acceleration = 3;
	turningRate = 3;
}

Speedboat::~Speedboat()
{

}

////////////////////////////////////////////////////

Frigate::Frigate(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381(mSceneMgr, id, name, pos)
{
	entityName = "Frigate" + std::to_string(id);
	maxSpeed = 12;
	acceleration = 2;
	turningRate = 2;
}

Frigate::~Frigate()
{

}

////////////////////////////////////////////////////

Alien::Alien(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381(mSceneMgr, id, name, pos)
{
	entityName = "Alien" + std::to_string(id);
	maxSpeed = 30;
	acceleration = 6;
	turningRate = 6;
}

Alien::~Alien()
{

}
