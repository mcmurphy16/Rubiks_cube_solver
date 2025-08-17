//
// Created by Chinmay on 8/12/2024.
//
#include <bits/stdc++.h>
using namespace std;
#include "DFSSolver.h"

#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver {
private:
    int max_depth;
    std::vector<GenericRubiksCube::MOVE> moves;

public:
    T rubiksCube;
    IDDFSSolver(T cube, int max_depth = 7)
        : rubiksCube(cube), max_depth(max_depth) {}

    std::vector<GenericRubiksCube::MOVE> solve() {
        for (int depth = 1; depth <= max_depth; ++depth) {
            DFSSolver<T, H> dfsSolver(rubiksCube, depth);
            if (!(moves = dfsSolver.solve()).empty()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif //IDDFSSOLVER_H
