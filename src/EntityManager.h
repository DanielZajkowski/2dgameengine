#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include "Component.h"
#include "Constants.h"
#include <iostream>
#include <vector>
#include <string>

class EntityManager
{
    private:
        std::vector<Entity*> entities;
    public:
        void ClearData();
        void Update(float deltaTime);
        void Render();
        void ListAllEntities() const;
        bool HasNoEntities();
        unsigned int GetEntityCount();
        Entity& AddEntity(std::string entityName, LayerType layer);
        std::vector<Entity*> GetEntities() const;
        std::vector<Entity *> GetEntitiesByLayer(LayerType layer) const;
        CollisionType CheckCollisions() const;
};

#endif