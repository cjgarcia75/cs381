/*
 * Christian Garcia
 * cj_garcia@sbcglobal.net
-----------------------------------------------------------------------------
Filename:    Aspect.cpp
-----------------------------------------------------------------------------
*/

#include "Aspect.h"

Aspect::Aspect(Entity381* ent)
{
	entity = ent;
	aspectType = NoneAspect;

//	std::cout << "Aspect entity address: " << this->entity << "\nAspect ent address: " << ent << "\n";
}
Aspect::~Aspect()
{
}

void Aspect::Tick(float dt)
{
//	std::cout << "Aspect entity name: " << entity->entityName << "\n";
//	std::cout << "Aspect tick entity address: " << entity << "\n";
}

Physics::Physics(Entity381* ent): Aspect{ent}
{
	aspectType = PhysicsAspect;
//	std::cout << "Physics entity address: " << this->entity << "\nPhysics ent address: " << ent << "\n";
}
Physics::~Physics(){}

void Physics::Tick(float dt)
{
	std::cout << "Physics tick entity name: " << entity->entityName << "\n";
	std::cout << "Phtysics speed: " << entity->speed << "\nPhysics heading: " << entity->heading << "\n";
	std::cout << "Physics dSpeed: " << entity->getDesiredSpeed() << "\nPhysics dHeading: " << entity->desiredHeading << "\n";
//	std::cout << "Physics dSpeed address: " << &(entity->desiredSpeed) << "\nPhysics dHeading address: " << &(entity->desiredHeading) << "\n";
//	std::cout << entity->maxSpeed << "\n";
//	std::cout << "physics tick entity address: " << entity << "\n";

//	float oldHeading = entity->heading;

	if(entity->speed < entity->desiredSpeed)
	{
		entity->speed += (entity->acceleration * dt);
//		if(entity->speed > entity->maxSpeed)
//		{
//			entity->speed = entity->maxSpeed;
//		}
	}
	if(entity->speed > entity->desiredSpeed)
	{
		entity->speed -= (entity->acceleration * dt);
//		if(entity->speed < entity->minSpeed)
//		{
//			entity->speed = entity->minSpeed;
//		}
	}

	if(entity->heading < entity->desiredHeading)
	{
		entity->heading += (entity->turningRate * dt);
//		if(entity->heading > 360)
//		{
//			entity->heading = 0;
//		}
	}
	if(entity->heading > entity->desiredHeading)
	{
		entity->heading -= (entity->turningRate * dt);
//		if(entity->heading < 0)
//		{
//			entity->heading = 360;
//		}
	}

//	entity->speed = 5;
//	entity->heading = 10;

	Ogre::Vector3 vel = Ogre::Vector3(0, 0, 0);
	vel.x = Ogre::Math::Cos(entity->heading, false) * entity->speed;
	vel.z = Ogre::Math::Sin(entity->heading, false) * entity->speed;
	entity->setVelocity(vel);

	Ogre::Vector3 pos = entity->getPosition() + (entity->getVelocity() * dt);
	entity->setPosition(pos);

//	entity->rotation = oldHeading - entity->heading;
}

//----------------------------------------------------------

Renderer::Renderer(Entity381* ent): Aspect{ent}
{
	aspectType = RendererAspect;
}
Renderer::~Renderer(){}

void Renderer::Tick(float dt)
{
	entity->getNode()->setPosition(entity->getPosition());
//	enitity->getNode()->resetOrientation();
//	entity->getNode()->yaw(Ogre::Degree(entity->rotation));
	entity->getNode()->setOrientation(Ogre::Quaternion(Ogre::Radian(Ogre::Degree(-1 * entity->heading * 55)), Ogre::Vector3(0, 1, 0)));

//	entity->getNode()->yaw(Ogre::Degree(5 * dt));
//	std::cout << "renderer tick\n";
//	std::cout << "Renderer tick entity name: " << entity->entityName << "\n";
//	std::cout << "Renderer tick entity address: " << entity << "\n";
}

