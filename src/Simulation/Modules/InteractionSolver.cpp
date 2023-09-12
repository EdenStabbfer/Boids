//
// Created by kufuk on 12.09.2023.
//

#include "../../../include/Simulation/Modules/InteractionSolver.h"

InteractionSolver::SolveMethod InteractionSolver::current = Each2Each;

void InteractionSolver::eachToEachSolve(LinearContainer<Boid>& container, Boid& target)
{
    int neighboringBoidsCnt{0};
    sf::Vector2f closeDistances, neighboringPositions, neighboringVelocities;

    for(auto& other: container)
    {
        if (other != target)
        {
            float dx = other.m_position.x - target.m_position.x;
            float dy = other.m_position.y - target.m_position.y;

            if (abs(dx) < Settings::Model::VisualRange && abs(dy) < Settings::Model::VisualRange)
            {
                float distSq = lenSq(other.m_position - target.m_position);
                if (distSq < Settings::Model::ProtectedRange * Settings::Model::ProtectedRange)
                {
                    closeDistances += target.m_position - other.m_position;
                }
                else if (distSq < Settings::Model::VisualRange * Settings::Model::VisualRange)
                {
                    neighboringVelocities += other.m_velocity;
                    neighboringPositions += other.m_position;
                    neighboringBoidsCnt++;
                }
            }
        }
    }

    if (neighboringBoidsCnt)
    {
        target.m_acceleration += (neighboringVelocities / (float)neighboringBoidsCnt - target.m_velocity) * Settings::Model::MathingFactor;
        target.m_acceleration += (neighboringPositions / (float)neighboringBoidsCnt - target.m_position) * Settings::Model::CenteringFactor;
    }

    target.stats.distToCenterOfMass = len(neighboringPositions / (float)neighboringBoidsCnt - target.m_position);

    target.m_acceleration += closeDistances * Settings::Model::AvoidFactor;
}

void InteractionSolver::solve(LinearContainer<Boid>& container, Boid& target)
{
    switch (current)
    {
        case Each2Each:
            eachToEachSolve(container, target);
            break;
        case Grid:
            eachToEachSolve(container, target);
    }
}
