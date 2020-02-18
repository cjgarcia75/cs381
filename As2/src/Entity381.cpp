/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    Entity381.cpp
-----------------------------------------------------------------------------
*/

#include "Entity381.h"

Entity381::Entity381(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos)
{
	entityName = name;
	position = pos;

	ent = mSceneMgr->createEntity(name.c_str());
	node = mSceneMgr->getRootSceneNode()->createChildSceneNode(pos);
	node->attachObject(ent);
	node->showBoundingBox(false);
}

Entity381::~Entity381()
{

}

void Entity381::Tick(float dt)
{

}

void Entity381::setPosition(Ogre::Vector3 pos)
{
	position = pos;
}
void Entity381::setVelocity(Ogre::Vector3 vel)
{
	velocity = vel;
}
