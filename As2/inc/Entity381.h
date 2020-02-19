/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
 -----------------------------------------------------------------------------
 Filename:    Entity381.h
 -----------------------------------------------------------------------------
 */
#ifndef __Entity381_h_
#define __Entity381_h_

#include "BaseApplication.h"
#include <string>

class Entity381{
public:
	Entity381(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos);
	virtual ~Entity381(void);
	
	void Tick(float dt);

	void setVelocity(Ogre::Vector3 vel);
	Ogre::Vector3 getVelocity();
	void ChangeShowBox();

private:
    std::string entityName;
    Ogre::Vector3 position;
    Ogre::Vector3 velocity;

    Ogre::Entity* ent;
    Ogre::SceneNode* node;

};

#endif // #ifndef __Entity381_h_
