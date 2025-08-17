//
// Created by Chinmay on 8/10/2024.
//

#include "GenericRubiksCube.h"

char GenericRubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:   return 'B';
        case COLOR::GREEN:  return 'G';
        case COLOR::RED:    return 'R';
        case COLOR::YELLOW: return 'Y';
        case COLOR::WHITE:  return 'W';
        case COLOR::ORANGE: return 'O';
    }return ' ';
}

string GenericRubiksCube::getMove(MOVE ind) {
    const static string moveStrings[] = {
        "L", "L'", "L2", "R", "R'", "R2", "U", "U'", "U2",
        "D", "D'", "D2", "F", "F'", "F2", "B", "B'", "B2"
    };
    return moveStrings[static_cast<int>(ind)];
}

GenericRubiksCube &GenericRubiksCube::move(MOVE ind) {
    using MoveFunc = GenericRubiksCube& (GenericRubiksCube::*)();
    const static MoveFunc moveFuncs[] = {
        &GenericRubiksCube::l, &GenericRubiksCube::lPrime, &GenericRubiksCube::l2,
        &GenericRubiksCube::r, &GenericRubiksCube::rPrime, &GenericRubiksCube::r2,
        &GenericRubiksCube::u, &GenericRubiksCube::uPrime, &GenericRubiksCube::u2,
        &GenericRubiksCube::d, &GenericRubiksCube::dPrime, &GenericRubiksCube::d2,
        &GenericRubiksCube::f, &GenericRubiksCube::fPrime, &GenericRubiksCube::f2,
        &GenericRubiksCube::b, &GenericRubiksCube::bPrime, &GenericRubiksCube::b2
    };
    return (this->*moveFuncs[static_cast<int>(ind)])();
}

GenericRubiksCube &GenericRubiksCube::invert(MOVE ind) {
    using MoveFunc = GenericRubiksCube& (GenericRubiksCube::*)();
    const static MoveFunc invertFuncs[] = {
        &GenericRubiksCube::lPrime, &GenericRubiksCube::l, &GenericRubiksCube::l2,
        &GenericRubiksCube::rPrime, &GenericRubiksCube::r, &GenericRubiksCube::r2,
        &GenericRubiksCube::uPrime, &GenericRubiksCube::u, &GenericRubiksCube::u2,
        &GenericRubiksCube::dPrime, &GenericRubiksCube::d, &GenericRubiksCube::d2,
        &GenericRubiksCube::fPrime, &GenericRubiksCube::f, &GenericRubiksCube::f2,
        &GenericRubiksCube::bPrime, &GenericRubiksCube::b, &GenericRubiksCube::b2
    };
    return (this->*invertFuncs[static_cast<int>(ind)])();
}

void GenericRubiksCube::print() const {
    auto printFace = [&](FACE face, int indent = 0) {
        for (int row = 0; row <=2; row++) {
            cout << string(indent, ' ');
            for (int col = 0; col <=2; col++) {
                cout << getColorLetter(getColor(face, row, col)) << " ";
            }
            cout << "\n";
        }
    };
    cout << "Rubik's Cube:\n\n";
    printFace(FACE::UP, 7);
    cout << "\n";
    for (int row = 0; row <=2; row++) {
        for (auto face : {FACE::LEFT, FACE::FRONT, FACE::RIGHT, FACE::BACK}) {
            printFace(face, 0);
            if (face != FACE::BACK) cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    printFace(FACE::DOWN, 7);
}

vector<GenericRubiksCube::MOVE> GenericRubiksCube::randomShuffleCube(unsigned int times) {
    vector<MOVE> moves_performed;
    srand(time(0));
    for (unsigned int i = 0; i < times; ++i) {
        MOVE move = static_cast<MOVE>(rand() % 18);
        moves_performed.push_back(move);
        this->move(move);
    }
    return moves_performed;
}

string GenericRubiksCube::getCornerColorString(uint8_t ind) const {
    const static array<tuple<FACE, int, int>, 3> cornerMap[8] = {
        make_tuple(FACE::UP, 2, 2), make_tuple(FACE::FRONT, 0, 2), make_tuple(FACE::RIGHT, 0, 0),  // UFR
        make_tuple(FACE::UP, 2, 0), make_tuple(FACE::FRONT, 0, 0), make_tuple(FACE::LEFT, 0, 2),   // UFL
        make_tuple(FACE::UP, 0, 0), make_tuple(FACE::BACK, 0, 2), make_tuple(FACE::LEFT, 0, 0),    // UBL
        make_tuple(FACE::UP, 0, 2), make_tuple(FACE::BACK, 0, 0), make_tuple(FACE::RIGHT, 0, 2),   // UBR
        make_tuple(FACE::DOWN, 0, 2), make_tuple(FACE::FRONT, 2, 2), make_tuple(FACE::RIGHT, 2, 0),// DFR
        make_tuple(FACE::DOWN, 0, 0), make_tuple(FACE::FRONT, 2, 0), make_tuple(FACE::LEFT, 2, 2), // DFL
        make_tuple(FACE::DOWN, 2, 2), make_tuple(FACE::BACK, 2, 0), make_tuple(FACE::RIGHT, 2, 2), // DBR
        make_tuple(FACE::DOWN, 2, 0), make_tuple(FACE::BACK, 2, 2), make_tuple(FACE::LEFT, 2, 0)   // DBL
    };
    string str = "";
    for (const auto& [face, row, col] : cornerMap[ind]) {
        str += getColorLetter(getColor(face, row, col));
    }
    return str;
}

uint8_t GenericRubiksCube::getCornerIndex(uint8_t ind) const {
    uint8_t ret = 0;
    for (char c : getCornerColorString(ind)) {
        ret |= (c == 'Y') << 2 | (c == 'O') << 1 | (c == 'G');
    }
    return ret;
}

uint8_t GenericRubiksCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);
    char primaryColor = corner.find_first_of("WY");
    return corner[1] == primaryColor ? 1 : (corner[2] == primaryColor ? 2 : 0);
}








