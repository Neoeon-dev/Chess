#include "Board.h"
#include <vector>

//Constructors Definition

Board::Board(){
    this->board = Default_Board;
    this->sideToMove = WHITE;
    this->castlingRights = Default_Rights;
    this->enPassantSquare = NO_SQUARE;
    this->prev_move = MoveState();
    this->BlackKing = D1;
    this->WhiteKing = D8;
}

Board::Board(std::array<std::array<Pieces, 8>, 8> board, Color sideToMove, CastlingRights castlingRights, Square enPassantSquare, MoveState prev_move, Square BlackKing, Square WhiteKing){
    this->board = board;
    this->sideToMove = sideToMove;
    this->castlingRights = castlingRights;
    this->enPassantSquare = enPassantSquare;
    this->prev_move = prev_move;
    this->BlackKing = BlackKing;
    this->WhiteKing = WhiteKing;
}

//Methods Definition

bool Board::isValidIndex(int row, int col){
    if(row >= 8 || row < 0) return false;
    if(col >= 8 || col < 0) return false;
    return true;
}

int Board::Occupied_King(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos){
    int position = pos, file = pos%8, rank = pos/8;
    std::vector<int> indexes;
}
