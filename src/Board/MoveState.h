#pragma once

#include "Move.h"

class MoveState{
public:
    Move move;
    Pieces CapturedPiece;
    CastlingRights oldcastlingRights;
    Square oldEnpassantSquare;
    int oldHalfMove;
    Hashing oldhash;

    //constructors declarations

    MoveState();

    MoveState(Move, Pieces, CastlingRights, Square, int, Hashing);

};