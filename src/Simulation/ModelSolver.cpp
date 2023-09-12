//
// Created by kufuk on 04.08.2023.
//
# include "../../include/Simulation/ModelSolver.h"

ModelSolver::ModelSolver(LinearContainer<Boid>& targets) : m_targets(targets)
{}

void ModelSolver::update()
{
    for (auto& obj: m_targets) {
        BoundariesSolver::solve(obj);
        wonder(obj);
        InteractionSolver::solve(m_targets, obj);
        obj.move();
    }
}

void ModelSolver::wonder(Boid& obj)
{
    obj.m_desiredDirection = norm(obj.m_desiredDirection + getRandomVector() * Settings::Boid::WonderStrength);
    obj.m_acceleration += norm(obj.m_desiredDirection * obj.m_maxSpeed - obj.m_velocity) * Settings::Boid::SteerStrength;
}

