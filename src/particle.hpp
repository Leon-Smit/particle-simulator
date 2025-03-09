#pragma once
#include <SFML/Graphics.hpp>

struct Particle
{
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float radius = 10.0f;

    Particle() = default;
    Particle(sf::Vector2f position_, float radius_)
        : position{position_},
          velocity{0.0f, 10.0f},
          acceleration{0.0f, 0.0f},
          radius{radius_} {}

    void update(float deltaTime) {
        velocity += acceleration;
        position += velocity * deltaTime;
        acceleration = {};
    }

    void accelerate(sf::Vector2f force) {
        acceleration += force;
    }
};
