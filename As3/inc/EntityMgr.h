/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    EntityMgr.h
-----------------------------------------------------------------------------
*/

#ifndef ENTITYMGR_H_
#define ENTITYMGR_H_

#include "Entity381.h"
#include <vector>

class EntityMgr{
public:
	EntityMgr(Ogre::SceneManager* mSceneMgr);
	virtual ~EntityMgr(void);

	void Tick(float dt);
	void CreateEntity(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos);
	void SelectNextEnt();
	void ChangeSpeed(float s);
	void ChangeHeading(float h);
	float getSpeed();
	float getHeading();
	float getMaxSpeed();

private:
	std::vector<Entity381> entities;
	unsigned int selectedEntity;
};

#endif /* ENTITYMGR_H_ */
