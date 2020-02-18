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
	Entity381* CreateEntity(std::string type, Ogre::Vector3 pos);

private:
	std::vector<Entity381> entities;
	int selectedEntity;

};

#endif /* ENTITYMGR_H_ */
