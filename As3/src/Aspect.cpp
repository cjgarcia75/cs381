/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    Aspect.cpp
-----------------------------------------------------------------------------
*/

#include "Aspect.h"

Aspect::Aspect(Entity381* ent){
	entity = ent;
	aspectType = NoneAspect;
}
Aspect::~Aspect(){}

Physics::Physics(Entity381 * ent): Aspect(ent) {
	aspectType = PhysicsAspect;
}
Physics::~Physics(){}

void Physics::Tick(float dt){
	if(entity->speed < entity->desiredSpeed)
	{
		entity->speed += (entity->acceleration * dt);
		if(entity->speed > entity->maxSpeed)
		{
			entity->speed = entity->maxSpeed;
		}
	}
	if(entity->speed > entity->desiredSpeed)
	{
		entity->speed -= (entity->acceleration * dt);
		if(entity->speed < entity->minSpeed)
		{
			entity->speed = entity->minSpeed;
		}
	}

	if(entity->heading < entity->desiredHeading)
	{
		entity->heading += (entity->turningRate * dt);
		if(entity->heading > 360)
		{
			entity->heading = 0;
		}
	}
	if(entity->heading > entity->desiredHeading)
	{
		entity->heading -= (entity->turningRate * dt);
		if(entity->heading < 0)
		{
			entity->heading = 360;
		}
	}

	std::cout << entity->speed << "\n" << entity->heading << "\n";

	Ogre::Vector3 vel = Ogre::Vector3(0, 0, 0);
	vel.x = cos(entity->heading) * entity->speed;
	vel.z = sin(entity->heading) * entity->speed;
	entity->setVelocity(vel);

	Ogre::Vector3 pos = entity->getPosition() + (entity->getVelocity() * dt);
	entity->setPosition(pos);
//	std::cout << "physics tick\n";
}

//----------------------------------------------------------

Renderer::Renderer(Entity381 * ent): Aspect(ent) {
	aspectType = RendererAspect;
}
Renderer::~Renderer(){}

void Renderer::Tick(float dt){
	entity->getNode()->setPosition(entity->getPosition());
	entity->getNode()->yaw(Ogre::Degree(entity->heading));
//	std::cout << "renderer tick\n";
}

