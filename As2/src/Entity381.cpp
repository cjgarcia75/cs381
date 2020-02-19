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

	if(name[0] == 'c')
		ent->setMaterialName("Examples/Rockwall");

	if(name[0] == 's')
		ent->setMaterialName("Examples/Chrome");
}

Entity381::~Entity381()
{

}

void Entity381::Tick(float dt)
{
	position += velocity * dt;
	node->setPosition(position);

	node->yaw(Ogre::Degree(0.03));
}

void Entity381::setVelocity(Ogre::Vector3 vel)
{
	velocity = vel;
}

void Entity381::ChangeShowBox()
{
	if(node->getShowBoundingBox())
		node->showBoundingBox(false);
	else
		node->showBoundingBox(true);
}
