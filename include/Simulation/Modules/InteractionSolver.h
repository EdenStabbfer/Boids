//
// Created by kufuk on 12.09.2023.
//

#ifndef INTERACTIONSOLVER_H
#define INTERACTIONSOLVER_H

#include "../../Entities/Boid.h"
#include "../../Container/LinearContainer.h"
#include "../../Utils/Settings.h"


class InteractionSolver
{
    enum SolveMethod : uint8_t
    {
        Each2Each,
        Grid
    };

public:
    InteractionSolver() = delete;

    // O(n²) complexity
    static void eachToEachSolve(LinearContainer<Boid>& container, Boid& target);

    // Solves boundaries using current method
    static void solve(LinearContainer<Boid>& container, Boid& target);

    // Current method
    static SolveMethod current;
};


#endif //INTERACTIONSOLVER_H
