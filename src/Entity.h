#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <map>
#include "./EntityManager.h"
#include "./Component.h"

class Component;
class EntityManager;

class Entity
{
    private:
        EntityManager& manager;
        bool isActive;
        std::map<const std::type_info*, Component*> componentTypeMap;

    public:
        std::string name;
        std::vector<Component*> components;
        Entity(EntityManager& manager);
        Entity(EntityManager&, std::string name);
        void Update(float deltaTime);
        void Render();
        void Destroy();
        bool IsActive() const;

        void ListAllComponents() const;

        template <typename T, typename... TArgs>
        T &AddComponent(TArgs &&... args)
        {
            T* newComponent(new T(std::forward<TArgs>(args)...));
            newComponent->componentName = typeid(T).name();
            newComponent->owner = this;
            components.emplace_back(newComponent);
            componentTypeMap[&typeid(*newComponent)] = newComponent;
            newComponent->Initialize();
            return *newComponent;
        }

        template <typename T>
        T* GetComponent()
        {
            return static_cast<T*>(componentTypeMap[&typeid(T)]);
        }

        template <typename T>
        bool HasComponent() const
        {
            //todo
        }
};

#endif