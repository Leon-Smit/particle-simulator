#pragma once
#include "particle.hpp"
#include <vector>

class Solver
{
public:
    Solver() = default;

    Particle &addObject(sf::Vector2f position, float radius)
    {
        Particle newParticle = Particle(position, radius);
        return objects.emplace_back(newParticle);
    }

    void update(float deltaTime)
    {
        applyGravity(deltaTime);
        updateObjects(deltaTime);
    }

    std::vector<Particle> &getObjects()
    {
        return objects;
    }

private:
    std::vector<Particle> objects;
    sf::Vector2f gravity = {0.0f, 1000.0f};

    void applyGravity(float deltaTime)
    {
        for (auto &obj : objects)
        {
            obj.accelerate(gravity * deltaTime);
        }
    }

    void updateObjects(float deltaTime)
    {
        for (auto &obj : objects)
        {
            obj.update(deltaTime);
        }
    }
};
