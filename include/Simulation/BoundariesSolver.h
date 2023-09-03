//
// Created by kufuk on 03.09.2023.
//

#ifndef BOUNDARIESSOLVER_H
#define BOUNDARIESSOLVER_H

#include "../Entities/Boid.h"
#include "../Utils/Settings.h"


/* Uses to define ways to resolve Out of borders conflict */
class BoundariesSolver
{
    enum SolveMethod : uint8_t
    {
        CONTINUOUS_BORDERS,
        AVOID_BORDERS
    };

public:
    BoundariesSolver() = delete;

    // Connects top to bottom and left to right and vice versa
    static void continuous(Boid& obj);

    // Makes the Boids avoid the boundaries
    static void bordersAvoid(Boid& obj);

    // Solves boundaries using current method
    static void solve(Boid& obj);

    // Current method
    static SolveMethod current;
};


#endif //BOUNDARIESSOLVER_H
