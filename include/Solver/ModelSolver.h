//
// Created by kufuk on 04.08.2023.
//

#ifndef MODELSOLVER_H
#define MODELSOLVER_H

#include <vector>

#include "../Entities/Boid.h"
#include "../Utils/Statistics.h"
#include "../Utils/Settings.h"

class ModelSolver
{
private:
    void solveInteraction(Boid& obj);
    void solveBoundaries1(Boid& obj);
    void solveBoundaries2(Boid& obj);
    static void wonder(Boid& obj);


public:
    explicit ModelSolver(std::vector<Boid>& targets);

    void update();

private:
    std::vector<Boid>& m_targets;

public:
    SolverStats stats;

};


#endif //MODELSOLVER_H
