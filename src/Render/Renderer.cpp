//
// Created by kufuk on 04.08.2023.
//

#include "Render/Renderer.h"

Renderer::Renderer(sf::RenderWindow *window,
                   IContainer<Boid> &targets,
                   const SolverStats &solverStats)
        :
        m_targets(targets),
        m_window(window),
        m_solverStats(solverStats) {}

void Renderer::render() {
    m_window->clear();

    sf::CircleShape shape(Settings::Boid::Size, 3);
    shape.setOrigin(Settings::Boid::Size, Settings::Boid::Size);

    for (const auto &obj: m_targets) {
        float angle = getAngleAbsolute(obj.m_velocity) + 90.0f;
        shape.setRotation(angle);

//        float t = (m_solverStats.maxNeighboursCount > 0) ? (float)obj.stats.neighboursCount / (float)m_solverStats.maxNeighboursCount : 0.0f;888
//        float t = 1 - sqrt(obj.stats.nearestDistToNeighbourSq) / Settings::Model::VisualRange;
        float t = 1.0 - obj.stats.distToCenterOfMass / Settings::Model::VisualRange;
        shape.setFillColor(palette(t));

        shape.setPosition(obj.m_position);
        m_window->draw(shape);
    }
    m_window->display();
}

sf::Color Renderer::palette(float t) {
    const sf::Vector3f a{0.500, 0.500, 0.500};
    const sf::Vector3f b{1.500, 0.500, 0.500};
    const sf::Vector3f c{0.800, 0.800, 0.800};
    const sf::Vector3f d{0.200, 0.533, 0.867};

    sf::Vector3f cosArg = 6.28318f * (c * t + d);
    cosArg.x = cos(cosArg.x);
    cosArg.y = cos(cosArg.y);
    cosArg.z = cos(cosArg.z);

    sf::Vector3f result = norm(a + b * cosArg);

    //std::cout << result.x << " " << result.y << " " << result.z << "\n";

    return {static_cast<sf::Uint8>(result.x * 256.0),
            static_cast<sf::Uint8>(result.y * 256.0),
            static_cast<sf::Uint8>(result.z * 256.0)};
}
