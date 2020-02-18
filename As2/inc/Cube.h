/*
 * Cube.h
 *
 *  Created on: Feb 18, 2020
 *      Author: cjgarcia
 */

#ifndef INC_CUBE_H_
#define INC_CUBE_H_

#include "Entity381.h"

class Cube : public Entity381
{
public:
	Cube(Ogre::SceneManager* mSceneMgr, std::string name, Ogre::Vector3 pos);
	~Cube();

	void Tick(float dt);
};

#endif /* INC_CUBE_H_ */
