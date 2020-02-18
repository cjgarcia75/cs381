/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    EntityMgr.h
-----------------------------------------------------------------------------
*/

#include "EntityMgr.h"

EntityMgr::EntityMgr(Ogre::SceneManager* mSceneMgr)
{
	selectedEntity = 0;
}

virtual EntityMgr::~EntityMgr(void)
{

}

void EntityMgr::Tick(float dt)
{

}

Entity381* EntityMgr::CreateEntity(std::string type, Ogre::Vector3 pos)
{

}
