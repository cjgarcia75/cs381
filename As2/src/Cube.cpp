/*
 * Cube.cpp
 *
 *  Created on: Feb 18, 2020
 *      Author: cjgarcia
 */

#include "Cube.h"

Cube::Cube(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos)
{
	Entity381(mSceneMgr, name, pos);
}
Cube::~Cube()
{

}

void Cube::Tick(float dt)
{

}

