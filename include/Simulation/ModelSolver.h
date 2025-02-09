//
// Created by kufuk on 04.08.2023.
//

#ifndef MODELSOLVER_H
#define MODELSOLVER_H

#include <vector>

#include "../Entities/Boid.h"
#include "../Utils/Statistics.h"
#include "../Utils/Settings.h"
#include "../Container/LinearContainer.h"

// Solver static modules
#include "Modules/BoundariesSolver.h"
#include "Modules/InteractionSolver.h"


class ModelSolver {
private:
    static void wonder(Boid &obj);


public:
    explicit ModelSolver(LinearContainer<Boid> &targets);

    void update();

private:
    LinearContainer<Boid> &m_targets;

public:
    SolverStats stats;

};


#endif //MODELSOLVER_H
