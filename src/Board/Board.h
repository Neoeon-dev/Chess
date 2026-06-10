#pragma once

#include "MoveState.h"

class Board{
public:
    std::array<std::array<Pieces, 8>, 8> board;
    Color sideToMove;
    CastlingRights castlingRights;
    Square enPassantSquare;
    MoveState prev_move;
    Square BlackKing;
    Square WhiteKing;

    //Constructors Declaration

    Board();

    Board(std::array<std::array<Pieces, 8>, 8> board, Color sideToMove, CastlingRights castlingRights, Square enPassantSquare, MoveState prev_move, Square BlackKing, Square WhiteKing);

    //Methods Declaration

    int Occupied_Queen(std::array<std::array<Pieces, 8>, 8>&);

    int Occupied_King(std::array<std::array<Pieces, 8>, 8>&, const Square&);

    int Occupied_Rook(std::array<std::array<Pieces, 8>, 8>&);

    int Occupied_Knight(std::array<std::array<Pieces, 8>, 8>&);

    int Occupied_Bishop(std::array<std::array<Pieces, 8>, 8>&);

    int Occupied_Pawn(std::array<std::array<Pieces, 8>, 8>&);

    std::array<std::array<Pieces, 8>, 8> Occupied();

    bool ischeck();

    bool ischeckmate();

    bool isstalemate();

    bool isLegalMove(const Move& move);

    bool isValidIndex(int row, int col);

};