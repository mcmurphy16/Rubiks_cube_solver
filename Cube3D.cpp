//
// Created by Chinmay on 8/11/2024.
//
#include "GenericRubiksCube.h"

class Cube3D : public GenericRubiksCube {
private:
    //Helper function
    void rotateFace(int ind) {
        char temp[3][3];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp[i][j] = cube[ind][i][j];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cube[ind][i][j] = temp[2 - j][i];
    }

public:
    char cube[6][3][3];
    Cube3D()  {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    cube[i][j][k] = getColorLetter(COLOR(i));
        }
    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B': return COLOR::BLUE;
            case 'R': return COLOR::RED;
            case 'G': return COLOR::GREEN;
            case 'O': return COLOR::ORANGE;
            case 'Y': return COLOR::YELLOW;
            case 'W': return COLOR::WHITE;
            default: return COLOR::WHITE; // Default case if an unknown color is encountered
        }
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; ++i)
            if (!std::all_of(&cube[i][0][0], &cube[i][3][0], [this, i](char color) {
                return color == getColorLetter(COLOR(i));
            })) return false;
        return true;
    }

    GenericRubiksCube& u() override {
        rotateFace(0);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube& uPrime() override { return u().u().u(); }
    GenericRubiksCube& u2() override { return u().u(); }

    GenericRubiksCube& l() override {
        rotateFace(1);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube& lPrime() override { return l().l().l(); }
    GenericRubiksCube& l2() override { return l().l(); }

    GenericRubiksCube& f() override {
        rotateFace(2);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube& fPrime() override { return f().f().f(); }
    GenericRubiksCube& f2() override { return f().f(); }

    GenericRubiksCube& r() override {
        rotateFace(3);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube& rPrime() override { return r().r().r(); }
    GenericRubiksCube& r2() override { return r().r(); }

    GenericRubiksCube& b() override {
        rotateFace(4);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube& bPrime() override { return b().b().b(); }
    GenericRubiksCube& b2() override { return b().b(); }

    GenericRubiksCube& d() override {
        rotateFace(5);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube& dPrime() override { return d().d().d(); }
    GenericRubiksCube& d2() override { return d().d(); }

    bool operator==(const Cube3D &r1) const {
        return std::equal(&cube[0][0][0], &cube[0][0][0] + 6*3*3, &r1.cube[0][0][0]);
    }

    GenericRubiksCube& operator=(const Cube3D &r1) {
        if (this != &r1) std::copy(&r1.cube[0][0][0], &r1.cube[0][0][0] + 6*3*3, &cube[0][0][0]);
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const Cube3D &r1) const {
        return hash<std::string>()(std::string(reinterpret_cast<const char*>(r1.cube), sizeof(r1.cube)));
    }
};



