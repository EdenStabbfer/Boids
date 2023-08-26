//
// Created by kufuk on 04.08.2023.
//
# include "../../include/Solver/ModelSolver.h"

ModelSolver::ModelSolver(std::vector<Boid>& targets) : m_targets(targets)
{}

void ModelSolver::update()
{
    for (auto& obj: m_targets) {
        solveBoundaries2(obj);
        wonder(obj);
        solveInteraction(obj);
        obj.move();
    }
}


void ModelSolver::solveBoundaries1(Boid& obj)
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

void ModelSolver::solveBoundaries2(Boid& obj)
{
    if (obj.m_position.x < 0.0) // left
        obj.m_position.x = (float)Settings::General::WindowWidth + obj.m_position.x;
    if (obj.m_position.y < 0.0) // top
        obj.m_position.y = (float)Settings::General::WindowHeight + obj.m_position.y;
    if (obj.m_position.x > (float)Settings::General::WindowWidth) // right
        obj.m_position.x -= (float)Settings::General::WindowWidth;
    if (obj.m_position.y > (float)Settings::General::WindowHeight) // bottom
        obj.m_position.y -= (float)Settings::General::WindowHeight;
}

void ModelSolver::wonder(Boid& obj)
{
    obj.m_desiredDirection = norm(obj.m_desiredDirection + getRandomVector() * Settings::Boid::WonderStrength);
    obj.m_acceleration += norm(obj.m_desiredDirection * obj.m_maxSpeed - obj.m_velocity) * Settings::Boid::SteerStrength;
}

void ModelSolver::solveInteraction(Boid& obj)
{
    int neighboringBoidsCnt{0};
    stats.maxNeighboursCount = 0;
    obj.stats.neighboursCount = 0;
    obj.stats.nearestDistToNeighbourSq = 0;
    sf::Vector2f closeDistances, neighboringPositions, neighboringVelocities;

    float protectedRangeSq{Settings::Model::ProtectedRange * Settings::Model::ProtectedRange};
    float visualRangeSq{Settings::Model::VisualRange * Settings::Model::VisualRange};

    for(auto& other: m_targets)
    {
        if (other != obj)
        {
            float dx = other.m_position.x - obj.m_position.x;
            float dy = other.m_position.y - obj.m_position.y;

            if (abs(dx) < Settings::Model::VisualRange && abs(dy) < Settings::Model::VisualRange)
            {
                float distSq = lenSq(other.m_position - obj.m_position);
                if (distSq < protectedRangeSq)
                {
                    closeDistances += obj.m_position - other.m_position;
                }
                else if (distSq < visualRangeSq)
                {
                    neighboringVelocities += other.m_velocity;
                    neighboringPositions += other.m_position;
                    neighboringBoidsCnt++;

                    if(obj.stats.nearestDistToNeighbourSq < distSq)
                        obj.stats.nearestDistToNeighbourSq = distSq;
                }
                else
                    obj.stats.nearestDistToNeighbourSq = Settings::Model::VisualRange;
            }
        }
    }

    if (neighboringBoidsCnt)
    {
        obj.m_acceleration += (neighboringVelocities / (float)neighboringBoidsCnt - obj.m_velocity) * Settings::Model::MathingFactor;
        obj.m_acceleration +=(neighboringPositions / (float)neighboringBoidsCnt - obj.m_position) * Settings::Model::CenteringFactor;
    }

    if(neighboringBoidsCnt > stats.maxNeighboursCount)
        stats.maxNeighboursCount = neighboringBoidsCnt;

    obj.m_acceleration += closeDistances * Settings::Model::AvoidFactor;
    obj.stats.neighboursCount = neighboringBoidsCnt;
}

