#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager
{

public:
	Client *firstClient;
	int Disappointment = 0;
	int InspectorDisappointment = 0;
	int LastInspectorDisappointment = 0;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity *> entities;
};