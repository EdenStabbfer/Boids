//
// Created by kufuk on 04.08.2023.
//

#ifndef MODELSOLVER_H
#define MODELSOLVER_H

#include <vector>

#include "../Entities/Boid.h"
#include "../Utils/Statistics.h"
#include "../Utils/Settings.h"
#include "../Container/IContainer.h"

// Solver static modules
#include "BoundariesSolver.h"


class ModelSolver
{
private:
    void solveInteraction(Boid& obj);
    static void wonder(Boid& obj);


public:
    explicit ModelSolver(IContainer<Boid>& targets);

    void update();

private:
    IContainer<Boid>& m_targets;

public:
    SolverStats stats;

};


#endif //MODELSOLVER_H
