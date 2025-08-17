//
// Created by Chinmay on 8/10/2024.
//

#ifndef GENERICRUBIKSCUBE_H
#define GENERICRUBIKSCUBE_H

/* a generic base class for multiple rubics cube models(representations)
 * this class provides a shared functionality between all models
 * we'll benchmark all models and observe the one which is performing better
 */
#include "bits/stdc++.h"
using namespace std;

class GenericRubiksCube {
public:
    /*defining option sets for faces,colours,and fixed 18 moves */
    enum class FACE {
      UP,LEFT,FRONT,RIGHT,BACK,DOWN
  };
    enum class COLOR {
        WHITE,GREEN,RED,BLUE,ORANGE,YELLOW
    };
    enum class MOVE {
        L,LPRIME,L2,R,RPRIME,R2,U,UPRIME,U2,D,DPRIM,D2,F,FPRIME,F2,B,BPRIME,B2
    };
    /* defining a purely virtual function which returns color of cell at (row,col) on the face
     * considering the face is pointing towards us,(0,0) is at top left and (5,5) is at bottom right   */
    virtual COLOR getColor(FACE face,unsigned row,unsigned col) const =0;
    /*defining a function returning first letter of the given COLOR. Eg. for Green: output is 'G'  */
    static char getColorLetter(COLOR color);
    /*defining a purely virtual function returning a bool if the cube is solved or not */
    virtual bool isSolved() const =0;
    /*returns the move in the string format. */
    static string getMove(MOVE ind);
    /*prints rubic cube in format
    *   * U
     *  L F R B
     *    D
     *
     */
    void print() const;
    /* Randomly shuffle the cube with 'times' moves and returns the moves performed. */
    vector<MOVE> randomShuffleCube(unsigned int times);
    /* Perform moves on the Rubik Cube  */
    GenericRubiksCube &move(MOVE ind);
    /* Invert a move */
    GenericRubiksCube &invert(MOVE ind);
    /* A purely virtual function for implementing rotational moves on the rubik cube
        L,LPRIME,L2,R,RPRIME,R2,U,UPRIME,U2,D,DPRIM,D2,F,FPRIME,F2,B,BPRIME,B2 */
    virtual GenericRubiksCube &f() = 0;
    virtual GenericRubiksCube &fPrime() = 0;
    virtual GenericRubiksCube &f2() = 0;
    virtual GenericRubiksCube &u() = 0;
    virtual GenericRubiksCube &uPrime() = 0;
    virtual GenericRubiksCube &u2() = 0;
    virtual GenericRubiksCube &l() = 0;
    virtual GenericRubiksCube &lPrime() = 0;
    virtual GenericRubiksCube &l2() = 0;
    virtual GenericRubiksCube &r() = 0;
    virtual GenericRubiksCube &d() = 0;
    virtual GenericRubiksCube &dPrime() = 0;
    virtual GenericRubiksCube &d2() = 0;
    virtual GenericRubiksCube &rPrime() = 0;
    virtual GenericRubiksCube &r2() = 0;
    virtual GenericRubiksCube &b() = 0;
    virtual GenericRubiksCube &bPrime() = 0;
    virtual GenericRubiksCube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};

#endif //GENERICRUBIKSCUBE_H
