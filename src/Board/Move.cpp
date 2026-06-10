#include "Move.h"

Move::Move(){
    this->from = A1;
    this->to = A1;
    this->promotion = QUEEN;
    this->isCastle = false;
    this->isEnPassant = false;
}

Move::Move(Square from, Square to, PieceType promotion, bool isEnPassant, bool isCastle){
    this->from = from;
    this->to = to;
    this->promotion = promotion;
    this->isEnPassant = isEnPassant;
    this->isCastle = isCastle;
}