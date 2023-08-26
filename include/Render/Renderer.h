//
// Created by kufuk on 04.08.2023.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "../Entities/Boid.h"
#include "../Utils/Statistics.h"
#include "../Utils/Settings.h"


class Renderer
{
private:
    static sf::Color palette(float t);

public:
    Renderer(sf::RenderWindow* window, std::vector<Boid>& targets, const SolverStats& solverStats);

    void render();

private:
    sf::RenderWindow* m_window;

    std::vector<Boid>& m_targets;
    const SolverStats& m_solverStats;
};


#endif //RENDERER_H
