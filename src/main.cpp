#include "particle.hpp"
#include "solver.hpp"
#include "renderer.hpp"
#include <SFML/Graphics.hpp>
#include "spawn.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 1;

    sf::RenderWindow window(
        sf::VideoMode({800, 800}),
        "Particle Simulator",
        sf::Style::Default,
        sf::State::Windowed,
        settings);

    window.setFramerateLimit(144);
    Renderer renderer(window);

    Solver solver;
    createRandomParticles(solver, 100);

    sf::Clock clock;
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        solver.update(deltaTime);
        renderer.render(solver);
        window.display();
    }
}
