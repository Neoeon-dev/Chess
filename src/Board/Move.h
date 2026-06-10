#pragma once

#include "../Enums/Enums.h"

class Move{
public:
    Square from;
    Square to;
    PieceType promotion;
    bool isEnPassant;
    bool isCastle;
    Move();
    Move(Square from, Square to, PieceType promotion, bool isEnPassant, bool isCastle);
};