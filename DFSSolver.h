//
// Created by Chinmay on 8/11/2024.
//

#include <bits/stdc++.h>
#include "GenericRubiksCube.h"
#ifndef DFSSOLVER_H
#define DFSSOLVER_H

template<typename T, typename H>
class DFSSolver {
private:
    std::vector<GenericRubiksCube::MOVE> moves;
    int max_depth;

    bool dfs(int depth) {
        if (rubiksCube.isSolved()) return true;
        if (depth > max_depth) return false;

        for (int i = 0; i < 18; ++i) {
            auto move = static_cast<GenericRubiksCube::MOVE>(i);
            rubiksCube.move(move);
            moves.push_back(move);
            if (dfs(depth + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(move);
        }
        return false;
    }

public:
    T rubiksCube;
    DFSSolver(T cube, int max_depth = 8) : rubiksCube(cube), max_depth(max_depth) {}

    std::vector<GenericRubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }
};


#endif //DFSSOLVER_H
