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

    std::vector<Move> generateMovesPiece(const Square&);

    std::vector<Move> generateMovesRook(const Square&);

    std::vector<Move> generateMovesBishop(const Square&);

    std::vector<Move> generateMovesKnight(const Square&);

    std::vector<Move> generateMovesQueen(const Square&);

    std::vector<Move> generateMovesKing(const Square&);

    std::vector<Move> generateMovesPawn(const Square&);

    //Helper Funtions

    std::vector<Square> Cross(const Square&,const Color&);

    std::vector<Square> Plus(const Square&,const Color&);

    std::vector<Square> L(const Square&,const Color&);

};

namespace BoardUtils{

    template <typename T>
    T mod(T a){
        if(a > T(0)){
            return a;
        }
        return T(-a);
    }

    bool isSameColor(const Pieces&, const Pieces&);
    
    bool isChessPiece(const Pieces&);

    PieceType what_piece(const Pieces&);

    bool isLegalMoveRook(const Move&);

    bool isLegalMoveBishop(const Move&);

    bool isLegalMoveKnight(const Move&);

    bool isLegalMoveQueen(const Move&);

    bool isLegalMoveKing(const Move&);

    bool isLegalMovePawn(const Move&, const Color&);

}