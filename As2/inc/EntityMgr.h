/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    EntityMgr.h
-----------------------------------------------------------------------------
*/

#ifndef ENTITYMGR_H_
#define ENTITYMGR_H_

#include "Sphere.h"
#include "Cube.h"
#include <vector>

class EntityMgr{
public:
	EntityMgr(Ogre::SceneManager* mSceneMgr);
	virtual ~EntityMgr(void);

	void Tick(float dt);
	void CreateEntity(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos);

private:
	std::vector<Entity381> entities;
	int selectedEntity;

};

#endif /* ENTITYMGR_H_ */
