#include "MoveState.h"

//constructors definitions

MoveState::MoveState(){
    this->move = Move();
    this->CapturedPiece = Pieces::EMPTY;
    this->oldcastlingRights = Default_Rights;
    this->oldEnpassantSquare = Square::NO_SQUARE;
    this->oldHalfMove = 0;
    this->oldhash = 0;
}

MoveState::MoveState(Move move, Pieces CapturedPiece, CastlingRights oldcastlingRights, Square oldEnpassantSquare, int oldHalfMove, Hashing oldhash){
    this->move = move;
    this->CapturedPiece = CapturedPiece;
    this->oldcastlingRights = oldcastlingRights;
    this->oldEnpassantSquare = oldEnpassantSquare;
    this->oldHalfMove = oldHalfMove;
    this->oldhash = oldhash;
}