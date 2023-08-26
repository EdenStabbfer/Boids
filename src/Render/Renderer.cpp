//
// Created by kufuk on 04.08.2023.
//

#include "../../include/Render/Renderer.h"
#include <iostream>

Renderer::Renderer(sf::RenderWindow* window,
                   std::vector<Boid> &targets,
                   const SolverStats& solverStats)
                   :
                   m_targets(targets),
                   m_window(window),
                   m_solverStats(solverStats)
{}

void Renderer::render()
{
    m_window->clear();

    sf::CircleShape shape(Settings::Boid::Size, 3);
    shape.setOrigin(Settings::Boid::Size, Settings::Boid::Size);

    for (const auto& obj: m_targets)
    {
        float angle = getAngleAbsolute(obj.m_velocity) + 90.0f;
        shape.setRotation(angle);

        //float t = (m_solverStats.maxNeighboursCount > 0) ? (float)obj.stats.neighboursCount / (float)m_solverStats.maxNeighboursCount : 0.0f;
        float t = 1 - sqrt(obj.stats.nearestDistToNeighbourSq) / Settings::Model::VisualRange;
        shape.setFillColor(palette(t));

        shape.setPosition(obj.m_position);
        m_window->draw(shape);
    }
    m_window->display();
}

sf::Color Renderer::palette(float t)
{
    static sf::Vector3f a{0.500, 0.500, 0.500};
    static sf::Vector3f b{0.500, 0.500, 0.500};
    static sf::Vector3f c{1.000, 1.000, 1.000};
    static sf::Vector3f d{0.000, 0.333, 0.667};

    sf::Vector3f cosArg = 6.28318f * (c*t + d);
    cosArg.x = cos(cosArg.x);
    cosArg.y = cos(cosArg.y);
    cosArg.z = cos(cosArg.z);

    sf::Vector3f result = a + b*cosArg;

    //std::cout << result.x << " " << result.y << " " << result.z << "\n";

    return {static_cast<sf::Uint8>(result.x * 256.0),
            static_cast<sf::Uint8>(result.y * 256.0),
            static_cast<sf::Uint8>(result.z * 256.0)};
}
