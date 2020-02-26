/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    Aspect.cpp
-----------------------------------------------------------------------------
*/

#ifndef INC_ASPECT_H_
#define INC_ASPECT_H_

#include "Entity381.h"
#include <cmath>

enum AspectType {
	RendererAspect= 0,
	PhysicsAspect,
	RotatorAspect,
	NoneAspect
};

class Aspect {

public:
	Aspect(Entity381* ent);
	virtual ~Aspect();

	virtual void Tick(float dt) = 0;
	Entity381 *entity;
	AspectType aspectType;
};

class Physics: public Aspect {
public:
	Physics(Entity381* ent);
	~Physics();
	void Tick(float dt);
};

class Renderer: public Aspect {
public:
	Renderer(Entity381* ent);
	~Renderer();
	void Tick(float dt);
};

#endif /* INC_ASPECT_H_ */
