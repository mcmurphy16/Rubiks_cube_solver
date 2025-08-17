#include <bits/stdc++.h>
using namespace std;
#include "Cube3D.cpp"
#include "DFSSolver.h"
#include "BFSSolver.h"
#include "IDDFSSolver.h"

int main() {
    // Cube3D object;
    //  object.randomShuffleCube();
    //  object.print();

    // if(!object.isSolved()) cout<<"\n UNSOLVED \n";
    // object.fPrime();
    // object.print();
    // if(object.isSolved()) cout<<"\n SOLVED \n";

    Cube3D cube;
    cube.print();

    vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    // DFS Solver Testing _____________________
    // DFSSolver<Cube3D, Hash3d> dfsSolver(cube, 8);
    // vector<GenericRubiksCube::MOVE> solve_moves = dfsSolver.solve();

    // BFS Solver Testing _____________________
    // BFSSolver<Cube3D, Hash3d> bfsSolver(cube);
    // vector<GenericRubiksCube::MOVE> solve_moves = bfsSolver.solve();

    // IDDFS Solver Testing _____________________
    IDDFSSolver<Cube3D, Hash3d> iddfsSolver(cube);
    vector<GenericRubiksCube::MOVE> solve_moves = iddfsSolver.solve();

    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    iddfsSolver.rubiksCube.print();

    return 0;
}
