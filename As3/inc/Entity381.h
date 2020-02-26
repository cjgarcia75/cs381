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
#include <vector>
#include <iostream>

class Aspect;

class Entity381{
public:
	Entity381(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos);
	virtual ~Entity381(void);
	
	virtual void Tick(float dt);

	void setVelocity(Ogre::Vector3 vel);
	void setPosition(Ogre::Vector3 pos);
	Ogre::Vector3 getVelocity();
	Ogre::Vector3 getPosition();
	Ogre::SceneNode* getNode();
	void ChangeShowBox();

	std::string entityName;
    float minSpeed = 0,
		  maxSpeed,
		  speed,
		  heading,
		  desiredSpeed,
		  desiredHeading,
		  acceleration,
		  turningRate;

private:
    std::string fileName;
    Ogre::Vector3 position;
    Ogre::Vector3 velocity;

    Ogre::Entity* ent;
    Ogre::SceneNode* node;

    std::vector<Aspect*> aspects;
};

class Destroyer : public Entity381{
public:
	Destroyer(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos);
	~Destroyer();
};

class Carrier : public Entity381{
public:
	Carrier(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos);
	~Carrier();
};

class Speedboat : public Entity381{
public:
	Speedboat(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos);
	~Speedboat();
};

class Frigate : public Entity381{
public:
	Frigate(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos);
	~Frigate();
};

class Alien : public Entity381{
public:
	Alien(Ogre::SceneManager* mSceneMgr, int id, std::string name, Ogre::Vector3 pos);
	~Alien();
};

#endif // #ifndef __Entity381_h_
