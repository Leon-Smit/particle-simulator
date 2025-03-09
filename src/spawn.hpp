#include "solver.hpp"
#include <random>

void createRandomParticles(Solver& solver, const uint32_t count)
    {
        std::vector<Particle> particles;
        particles.reserve(count);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(0.0f, 1.0f);

        for (uint32_t i{count}; i--;)
        {
            const float x = dis(gen) * 800;
            const float y = dis(gen) * 800;
            solver.addObject({x, y}, 10.f);
        }
    }