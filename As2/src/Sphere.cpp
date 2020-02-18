/*
 * Sphere.cpp
 *
 *  Created on: Feb 18, 2020
 *      Author: cjgarcia
 */

#include "Sphere.h"

Sphere::Sphere(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos)
{
	Entity381(mSceneMgr, name, pos);
}
Sphere::~Sphere()
{

}

void Sphere::Tick(float dt)
{

}
