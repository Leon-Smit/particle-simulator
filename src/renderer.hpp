#pragma once
#include "solver.hpp"
#include <SFML/Graphics.hpp>

class Renderer
{
public:
    Renderer(sf::RenderTarget &target_) : target{target_} {}

    void render(Solver &solver)
    {
        sf::CircleShape circle{1.0f};
        circle.setPointCount(32);

        const auto &objects = solver.getObjects();

        for (const Particle &obj : objects)
        {
            circle.setPosition(obj.position);
            circle.setScale(sf::Vector2f(obj.radius, obj.radius));
            circle.setFillColor({sf::Color::Blue});
            target.draw(circle);
        }
    };

private:
    sf::RenderTarget &target;
};
