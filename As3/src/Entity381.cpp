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

	speed = 0;
	heading = 0;
	desiredSpeed = 0;
	desiredHeading = 0;
	rotation = 0;

	ent = mSceneMgr->createEntity(fileName.c_str());
	node = mSceneMgr->getRootSceneNode()->createChildSceneNode(pos);
	node->attachObject(ent);
	node->showBoundingBox(false);

	//aspects.clear();
	Physics* phx = new Physics(this);
	aspects.push_back((Aspect*) phx);
	Renderer *rndrr = new Renderer(this);
	aspects.push_back((Aspect*) rndrr);

//	Aspect* asp = new Aspect(this);
//	aspects.push_back(asp);

	std::cout << "Entity381 entity address: " << this << "\nEntity381 physics ent address: " << aspects[0]->entity << "\n";
}

Entity381::~Entity381()
{
}

void Entity381::Tick(float dt)
{
	for(unsigned int i = 0; i < aspects.size(); i++)
	{
		aspects[i]->Tick(dt);
//		std::cout << "Entity tick entity address: " << this << " physics entity address: " <<  aspects[i]->entity << "\n";

	}
//	std::cout << speed << "\n" << heading << "\n";
//	std::cout << "Entity381 entity name: " << entityName << "\n";
//	std::cout<< "Entity381 dSpeed: " << desiredSpeed << "\nEntity381 dHeading: " << desiredHeading << "\n";
//	std::cout<< "Entity381 dSpeed address: " << &(desiredSpeed) << "\nEntity381 dHeading address: " << &(desiredHeading) << "\n";
//	std::cout << "Entity tick entity address: " << this << "\n";
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

float Entity381::getDesiredSpeed()
{
	return desiredSpeed;
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

Destroyer::Destroyer(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381{mSceneMgr, id, name, pos}
{
	entityName = "Destroyer" + std::to_string(id);
	maxSpeed = 40;
	acceleration = 10;
	turningRate = 0.25;
}

Destroyer::~Destroyer()
{

}

////////////////////////////////////////////////////

Carrier::Carrier(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381{mSceneMgr, id, name, pos}
{
	entityName = "Carrier" + std::to_string(id);
	maxSpeed = 50;
	acceleration = 5;
	turningRate = 0.1;
}

Carrier::~Carrier()
{

}

////////////////////////////////////////////////////

Speedboat::Speedboat(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381{mSceneMgr, id, name, pos}
{
	entityName = "Speedboat" + std::to_string(id);
	maxSpeed = 40;
	acceleration = 30;
	turningRate = 5;
}

Speedboat::~Speedboat()
{

}

////////////////////////////////////////////////////

Frigate::Frigate(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381{mSceneMgr, id, name, pos}
{
	entityName = "Frigate" + std::to_string(id);
	maxSpeed = 30;
	acceleration = 15;
	turningRate = 0.35;
}

Frigate::~Frigate()
{

}

////////////////////////////////////////////////////

Alien::Alien(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos) : Entity381{mSceneMgr, id, name, pos}
{
	entityName = "Alien" + std::to_string(id);
	maxSpeed = 50;
	acceleration = 50;
	turningRate = 2.5;
}

Alien::~Alien()
{

}
