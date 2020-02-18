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

void EntityMgr::CreateEntity(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos)
{
	if(name[0] == 'c')
	{
		Cube* cube = new Cube(mSceneMgr, name, pos);
		entities.push_back((*cube));
	}
	else if(name[0] == 's')
	{

	}
}
