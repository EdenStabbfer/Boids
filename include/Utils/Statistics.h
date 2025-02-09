//
// Created by kufuk on 08.08.2023.
//

#ifndef STATISTICS_H
#define STATISTICS_H

#include "Statistics.h"

struct SolverStats {
    int maxNeighboursCount{0};
};

struct BoidStats {
    int   neighboursCount{0};
    float nearestDistToNeighbourSq{0};
    float distToCenterOfMass{0};
};

#endif //STATISTICS_H
