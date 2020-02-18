/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    Entity381.cpp
-----------------------------------------------------------------------------
*/

#include "Entity381.h"

Entity381::Entity381(std::string type, std::string name, Ogre::Vector3 pos)
{
	entityType = type;
	entityName = name;
	position = pos;

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
