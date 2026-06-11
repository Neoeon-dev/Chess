#include "Board.h"


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
    if(this->board[row][col] != EMPTY && this->board[row][col] != OCCUPIED) return false;
    return true;
}

//Occupied function supporters

int Board::Occupied_King(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos){
    int position = pos, file = pos%8, rank = pos/8, count = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            if(isValidIndex(rank + i, file + j)){
                board_occupied[rank+i][file+j] = OCCUPIED;
                count++;
            }
            if(board[rank + i][file+j] != EMPTY && board[rank + i][file+j] != OCCUPIED){
                board_occupied[rank+i][file+j] = OCCUPIEDPIECE;
            }
        }
    }
    if(!count) return 0;
    return 1;
}

int Board::Occupied_Rook(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos){
    int file = pos%8, rank = pos/8, count = 0;
    for(int i = 0;i<(8-rank);i++){
        if(isValidIndex(rank + i, file)){
            count++;
            board_occupied[rank + i][file] = OCCUPIED;
        }
        if(board[rank + i][file] != EMPTY && board[rank + i][file] != OCCUPIED){
            board_occupied[rank+i][file] = OCCUPIEDPIECE;
            break;
        }
    }
    for(int i = -1;i>=(-rank);i--){
        if(isValidIndex(rank + i, file)){
            count++;
            board_occupied[rank + i][file] = OCCUPIED;
        }
        if(board[rank + i][file] != EMPTY && board[rank + i][file] != OCCUPIED){
            board_occupied[rank+i][file] = OCCUPIEDPIECE;
            break;
        }
    }
    for(int i = 0;i<(8-file);i++){
        if(isValidIndex(rank, file + i)){
            count++;
            board_occupied[rank][file + i] = OCCUPIED;
        }
        if(board[rank][file + i] != EMPTY && board[rank][file + i] != OCCUPIED){
            board_occupied[rank][file + i] = OCCUPIEDPIECE;
            break;
        }
    }
    for(int i = -1;i>=(-file);i--){
        if(isValidIndex(rank, file + i)){
            count++;
            board_occupied[rank][file+i] = OCCUPIED;
        }
        if(board[rank][file + i] != EMPTY && board[rank][file + i] != OCCUPIED){
            board_occupied[rank][file+i] = OCCUPIEDPIECE;
            break;
        }
    }
    if(!count) return 0;
    return 1;
}

int Board::Occupied_Bishop(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos){
    int file = pos%8, rank = pos/8, count = 0, URlimit = (rank > file)?(8-rank):(8-file), LLlimit = (rank > file)?file:rank, ULlimit = (rank + file < 8)?file: (8 - rank), LRlimit = (rank+file < 8)?rank:(8-file);
    for(int i = 1;i<URlimit;i++){
        if(isValidIndex(rank+i, file+i)){
            count++;
            board_occupied[rank+i][file+i] = OCCUPIED;
        }
        if(board[rank+i][file+i] != EMPTY && board[rank+i][file+i] != OCCUPIED){
            board_occupied[rank+i][file+i] = OCCUPIEDPIECE;
            break;
        }
    }
    for(int i = 1;i<=LLlimit;i++){
        if(isValidIndex(rank-i, file-i)){
            count++;
            board_occupied[rank-i][file-i] = OCCUPIED;
        }
        if(board[rank-i][file-i] != EMPTY && board[rank-i][file-i] != OCCUPIED){
            board_occupied[rank-i][file-i] = OCCUPIEDPIECE;
            break;
        }
    }
    for(int i = 1;i<=ULlimit;i++){
        if(isValidIndex(rank+i, file-i)){
            count++;
            board_occupied[rank+i][file-i] = OCCUPIED;
        }
        if(board[rank+i][file-i] != EMPTY && board[rank+i][file-i] != OCCUPIED){
            board_occupied[rank+i][file-i] = OCCUPIEDPIECE;
            break;
        }
    }
    for(int i = 1;i <= LRlimit;i++){
        if(isValidIndex(rank-i, file+i)){
            count++;
            board_occupied[rank-i][file+i] = OCCUPIED;
        }
        if(board[rank-i][file+i] != EMPTY && board[rank-i][file+i] != OCCUPIED){
            board_occupied[rank-i][file+i] = OCCUPIEDPIECE;
            break;
        }
    }
    if(!count) return 0;
    return 1;
}

int Board::Occupied_Queen(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos){
    int k1 = Occupied_Bishop(board_occupied, pos), k2 = Occupied_Rook(board_occupied, pos);
    if(k1 || k2) return 1;
    return 0;
}

int Board::Occupied_Knight(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos){
    int file = pos%8, rank = pos/8, count = 0;
    for(int i = -1;i<1;i++){
        if(i == 0) continue;
        if(isValidIndex(rank + 2*i, file + i)){
            count++;
            board_occupied[rank + 2*i][file + i] = OCCUPIED;
        }

        if(isValidIndex(rank + i, file + 2*i)){
            count++;
            board_occupied[rank + i][file + 2*i] = OCCUPIED;
        }
        if(board[rank + i][file + 2*i] != EMPTY && board[rank + i][file + 2*i] != OCCUPIED){
            board_occupied[rank+i][file+2*i] = OCCUPIEDPIECE;
        }
        if(board[rank + 2*i][file+i] != EMPTY && board[rank + 2*i][file + i] != OCCUPIED){
            board_occupied[rank+2*i][file+i] = OCCUPIEDPIECE;
        }
    }
    for(int i = -1;i<1;i++){
        if(i == 0) continue;
        if(isValidIndex(rank + 2*i, file - i)){
            count++;
            board_occupied[rank + 2*i][file - i] = OCCUPIED;
        }
        if(isValidIndex(rank + i, file - 2*i)){
            count++;
            board_occupied[rank + i][file - 2*i] = OCCUPIED;
        }
        if(board[rank + 2*i][file - i] != EMPTY && board[rank + 2*i][file - i] != OCCUPIED){
            board_occupied[rank + 2*i][file - i] = OCCUPIEDPIECE;
        }
        if(board[rank + i][file - 2*i] != EMPTY && board[rank + i][file - 2*i] != OCCUPIED){
            board_occupied[rank+i][file - 2*i] = OCCUPIEDPIECE;
        }
    }
    if(!count){
        return 0;
    }
    return 1;
}

int Board::Occupied_Pawn(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos){
    int side = 1;
    if(sideToMove == BLACK){
        side = -1;
    }
    int file = pos%8, rank = pos/8, count = 0;
    for(int i = -1;i<1;i++){
        if(i==0) continue;
        if(isValidIndex(rank + side, file + i)){
            count++;
            board_occupied[rank + side][file + i] = OCCUPIED;
        }
        if(board[rank + side][file+i] != EMPTY && board[rank + side][file + i] != OCCUPIED){
            board_occupied[rank + side][file + i] = OCCUPIEDPIECE;
        }
    }
    if(!count) return 0;
    return 1;
}

//occupied funtion

std::array<std::array<Pieces, 8>, 8> Board::Occupied(){
    std::array<std::array<Pieces, 8>, 8> board_occupied;
    int side = 0;
    if(sideToMove == BLACK) side = 1;
    board_occupied = board;
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board[i][j]%2 == 1 && side == 0){
                Square pos = (Square)(i*8+j);
                switch(board[i][j]){
                    case WPAWN:
                        Occupied_Pawn(board_occupied, pos);
                        break;
                    case WROOK:
                        Occupied_Rook(board_occupied, pos);
                        break;
                    case WKNIGHT:
                        Occupied_Knight(board_occupied, pos);
                        break;
                    case WBISHOP:
                        Occupied_Bishop(board_occupied, pos);
                        break;
                    case WQUEEN:
                        Occupied_Queen(board_occupied, pos);
                        break;
                    case WKING:
                        Occupied_King(board_occupied, pos);
                        break;
                }
            }
            if(board[i][j]%2 == 0 && side == 1){
                Square pos = (Square)(i*8+j);
                switch(board[i][j]){
                    case BPAWN:
                        Occupied_Pawn(board_occupied, pos);
                        break;
                    case BROOK:
                        Occupied_Rook(board_occupied, pos);
                        break;
                    case BKNIGHT:
                        Occupied_Knight(board_occupied, pos);
                        break;
                    case BBISHOP:
                        Occupied_Bishop(board_occupied, pos);
                        break;
                    case BQUEEN:
                        Occupied_Queen(board_occupied, pos);
                        break;
                    case BKING:
                        Occupied_King(board_occupied, pos);
                        break;
                }
            }
        }
    }
    return board_occupied;
}

//check funtions

bool Board::ischeck(){
    std::array<std::array<Pieces, 8>, 8> board_occupied = Occupied();
    if(sideToMove == WHITE){
        int file = WhiteKing%8, rank = WhiteKing/8;
        if(board_occupied[file][rank] == OCCUPIED){
            return true;
        }
    }
    else{
        int file = BlackKing%8, rank = WhiteKing/8;
        if(board_occupied[file][rank] == OCCUPIED){
            return true;
        }
    }
    return false;
}

bool Board::ischeckmate(){
    int file, rank;
    std::array<std::array<Pieces, 8>, 8> board_occupied = Occupied();
    if(sideToMove == WHITE){
        file = WhiteKing%8, rank = WhiteKing/8;
    }
    else{
        file = BlackKing%8, rank = BlackKing/8;
    }
    Color oppositeSide = (sideToMove == WHITE)?BLACK:WHITE;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            if(isValidIndex(rank + i, file + j)){
                if(board_occupied[i][j] == EMPTY){
                    return true;
                }
            }
        }
    }
}


