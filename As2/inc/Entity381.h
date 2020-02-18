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
	Entity381(std::string type, std::string name, Ogre::Vector3 pos);
	virtual ~Entity381(void);
	
	void Tick(float dt);

	void setPosition(Ogre::Vector3 pos);
	void setVelocity(Ogre::Vector3 vel);

private:
    std::string entityType;
    std::string entityName;
    Ogre::Vector3 position;
    Ogre::Vector3 velocity;
    Ogre::Entity* ent;
    Ogre::SceneNode* node;

};

#endif // #ifndef __Entity381_h_
