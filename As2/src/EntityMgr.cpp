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

EntityMgr::~EntityMgr(void)
{

}

void EntityMgr::Tick(float dt)
{
	for(unsigned int i = 0; i < entities.size(); i++)
	{
		entities[i].Tick(dt);
	}
}

void EntityMgr::CreateEntity(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos)
{
	Entity381* temp;

	if(name[0] == 'c')
	{
		temp = new Cube(mSceneMgr, name, pos);
	}
	else if(name[0] == 's')
	{
		temp = new Sphere(mSceneMgr, name, pos);
	}

	if(entities.size() == 0)
		temp->ChangeShowBox();

	entities.push_back((*temp));
}

void EntityMgr::SelectNextEnt()
{
	entities[selectedEntity].ChangeShowBox();

	selectedEntity++;

	if(selectedEntity == entities.size())
		selectedEntity = 0;

	entities[selectedEntity].ChangeShowBox();
}

void EntityMgr::ChangeVelocity(Ogre::Vector3 vel)
{
	entities[selectedEntity].setVelocity(vel);
}
