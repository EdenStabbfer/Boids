//
// Created by kufuk on 03.09.2023.
//
#include "../../../include/Simulation/Modules/BoundariesSolver.h"


BoundariesSolver::SolveMethod BoundariesSolver::current = CONTINUOUS_BORDERS;

void BoundariesSolver::continuous(Boid &obj)
{
    // Left
    if (obj.m_position.x < 0.0)
        obj.m_position.x = (float)Settings::General::WindowWidth + obj.m_position.x;

    // Top
    if (obj.m_position.y < 0.0)
        obj.m_position.y = (float)Settings::General::WindowHeight + obj.m_position.y;

    // Right
    if (obj.m_position.x > (float)Settings::General::WindowWidth)
        obj.m_position.x -= (float)Settings::General::WindowWidth;

    // Bottom
    if (obj.m_position.y > (float)Settings::General::WindowHeight)
        obj.m_position.y -= (float)Settings::General::WindowHeight;
}

void BoundariesSolver::bordersAvoid(Boid &obj)
{
    // Left
    if (obj.m_position.x < Settings::Model::WindowMargin)
        obj.m_acceleration.x += (Settings::Model::WindowMargin - obj.m_position.x) * Settings::Model::TurnFactor;

    // Top
    if (obj.m_position.y < Settings::Model::WindowMargin)
        obj.m_acceleration.y += (Settings::Model::WindowMargin - obj.m_position.y) * Settings::Model::TurnFactor;

    // Right
    if (obj.m_position.x > (float)Settings::General::WindowWidth - Settings::Model::WindowMargin)
        obj.m_acceleration.x += ((float)Settings::General::WindowWidth - Settings::Model::WindowMargin - obj.m_position.x) * Settings::Model::TurnFactor;

    // Bottom
    if (obj.m_position.y > (float)Settings::General::WindowHeight - Settings::Model::WindowMargin)
        obj.m_acceleration.y += ((float)Settings::General::WindowHeight - Settings::Model::WindowMargin - obj.m_position.y) * Settings::Model::TurnFactor;
}

void BoundariesSolver::solve(Boid& obj)
{
    switch (current)
    {
        case CONTINUOUS_BORDERS:
            continuous(obj);
            break;
        case AVOID_BORDERS:
            bordersAvoid(obj);
    }
}
