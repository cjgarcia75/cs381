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

void EntityMgr::CreateEntity(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos)
{
	Entity381* temp;

	if(name == "ddg51.mesh")
	{
		temp = new Destroyer(mSceneMgr, id, name, pos);
	}
	if(name == "cvn68.mesh")
	{
		temp = new Carrier(mSceneMgr, id, name, pos);
	}
	if(name == "cigarette.mesh")
	{
		temp = new Speedboat(mSceneMgr, id, name, pos);
	}
	if(name == "sleek.mesh")
	{
		temp = new Frigate(mSceneMgr, id, name, pos);
	}
	if(name == "alienship.mesh")
	{
		temp = new Alien(mSceneMgr, id, name, pos);
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

void EntityMgr::ChangeSpeed(float s)
{
	entities[selectedEntity].desiredSpeed = s;
//	std::cout << s << "\n";
//	std::cout << "EntityMgr dSpeed: " << entities[selectedEntity].desiredSpeed << "\n";
}

void EntityMgr::ChangeHeading(float h)
{
	entities[selectedEntity].desiredHeading = h;
//	std::cout << h << "\n";
//	std::cout << "EntityMgr dHeading: " << entities[selectedEntity].desiredHeading << "\n";
}

float EntityMgr::getSpeed()
{
	return(entities[selectedEntity].speed);
}

float EntityMgr::getHeading()
{
	return(entities[selectedEntity].heading);
}

float EntityMgr::getMaxSpeed()
{
	return(entities[selectedEntity].maxSpeed);
}
