/*
 * Sphere.h
 *
 *  Created on: Feb 18, 2020
 *      Author: cjgarcia
 */

#ifndef INC_SPHERE_H_
#define INC_SPHERE_H_

#include "Entity381.h"

class Sphere : public Entity381
{
public:
	Sphere(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos);
	~Sphere();

	void Tick(float dt);
};

#endif /* INC_SPHERE_H_ */
