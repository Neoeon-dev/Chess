#pragma once

#include "MoveState.h"
#include <vector>

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

    int Occupied_Queen(std::array<std::array<Pieces, 8>, 8>&, const Square&);

    int Occupied_King(std::array<std::array<Pieces, 8>, 8>&, const Square&);

    int Occupied_Rook(std::array<std::array<Pieces, 8>, 8>&, const Square&);

    int Occupied_Knight(std::array<std::array<Pieces, 8>, 8>&, const Square&);

    int Occupied_Bishop(std::array<std::array<Pieces, 8>, 8>&, const Square&);

    int Occupied_Pawn(std::array<std::array<Pieces, 8>, 8>&, const Square&, int);

    std::array<std::array<Pieces, 8>, 8> Occupied(int);

    std::vector<Square> Attackers(const Square& pos, Color side);

    bool ischeck();

    bool ischeckmate();

    bool isstalemate();

    bool isLegalMove(const Move&);

    bool isValidIndex(int, int);

    bool isValid(int, int);

    bool isEnpassant(const Square&, const Square&);

    Board movePiece(const Move&);

    //Helper Funtions

    std::vector<Square> Cross(const Square&,const Color&);

    std::vector<Square> Plus(const Square&,const Color&);

    std::vector<Square> L(const Square&,const Color&);
};