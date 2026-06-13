#include "Board.h"

//Helper functions

std::vector<Square> Board::Cross(const Square& pos,const Color& side){
    std::vector<Square> attackers;
    int file = pos%8, rank = pos/8, URlimit = (rank > file)?(8-rank):(8-file), LLlimit = (rank > file)?file:rank, ULlimit = (rank + file < 8)?file: (8 - rank), LRlimit = (rank+file < 8)?rank:(8-file);
    for(int i = 1;i<URlimit;i++){
        if(!isValid(rank+i, file+i)) continue;
        if(board[rank+i][file+i] != EMPTY && board[rank+i][file+i] != OCCUPIED){
            int row = rank + i, col = file + i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WBISHOP && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BBISHOP && side == WHITE) attackers.push_back(index);
            if(board[row][col] == WQUEEN && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BQUEEN && side == WHITE) attackers.push_back(index);
            break;
        }
    }
    for(int i = 1;i<=LLlimit;i++){
        if(!isValid(rank-i, file-i)) continue;
        if(board[rank-i][file-i] != EMPTY && board[rank-i][file-i] != OCCUPIED){
            int row = rank - i, col = file - i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WBISHOP && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BBISHOP && side == WHITE) attackers.push_back(index);
            if(board[row][col] == WQUEEN && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BQUEEN && side == WHITE) attackers.push_back(index);
            break;
        }
    }
    for(int i = 1;i<=ULlimit;i++){
        if(!isValid(rank+i, file-i)) continue;
        if(board[rank+i][file-i] != EMPTY && board[rank+i][file-i] != OCCUPIED){
            int row = rank + i, col = file - i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WBISHOP && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BBISHOP && side == WHITE) attackers.push_back(index);
            if(board[row][col] == WQUEEN && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BQUEEN && side == WHITE) attackers.push_back(index);
            break;
        }
    }
    for(int i = 1;i <= LRlimit;i++){
        if(!isValid(rank-i, file+i)) continue;
        if(board[rank-i][file+i] != EMPTY && board[rank-i][file+i] != OCCUPIED){
            int row = rank - i, col = file + i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WBISHOP && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BBISHOP && side == WHITE) attackers.push_back(index);
            if(board[row][col] == WQUEEN && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BQUEEN && side == WHITE) attackers.push_back(index);
            break;
        }
    }
    if(side == BLACK){
        if(isValid(rank+1, file - 1) && board[rank-1][file - 1] == WPAWN) attackers.push_back((Square)((rank+1)*8 + (file-1)));
        if(isValid(rank+1, file + 1) && board[rank-1][file + 1] == WPAWN) attackers.push_back((Square)((rank+1)*8 + (file+1)));
    }
    else{
        if(isValid(rank-1, file-1) && board[rank-1][file-1] == BPAWN) attackers.push_back((Square)((rank-1)*8 + (file-1)));
        if(isValid(rank-1, file+1) && board[rank-1][file+1] == BPAWN) attackers.push_back((Square)((rank-1)*8 + (file+1)));
    }
    if(side == BLACK){
        if(isValid(rank+1, file - 1) && board[rank+1][file - 1] == WKING) attackers.push_back((Square)((rank+1)*8 + (file-1)));
        if(isValid(rank+1, file + 1) && board[rank+1][file + 1] == WKING) attackers.push_back((Square)((rank+1)*8 + (file+1)));
        if(isValid(rank-1, file-1) && board[rank-1][file-1] == WKING) attackers.push_back((Square)((rank-1)*8 + (file-1)));
        if(isValid(rank-1, file+1) && board[rank-1][file+1] == WKING) attackers.push_back((Square)((rank-1)*8 + (file+1)));
    }
    else{
        if(isValid(rank+1, file - 1) && board[rank+1][file - 1] == BKING) attackers.push_back((Square)((rank+1)*8 + (file-1)));
        if(isValid(rank+1, file + 1) && board[rank+1][file + 1] == BKING) attackers.push_back((Square)((rank+1)*8 + (file+1)));
        if(isValid(rank-1, file-1) && board[rank-1][file-1] == BKING) attackers.push_back((Square)((rank-1)*8 + (file-1)));
        if(isValid(rank-1, file+1) && board[rank-1][file+1] == BKING) attackers.push_back((Square)((rank-1)*8 + (file+1)));
    }
    return attackers;
}

std::vector<Square> Board::Plus(const Square& pos,const Color& side){
    std::vector<Square> attackers;
    int file = pos%8, rank = pos/8, count = 0;
    for(int i = 0;i<(8-rank);i++){
        if(!isValid(rank + i, file)) continue;
        if(board[rank + i][file] != EMPTY && board[rank + i][file] != OCCUPIED){
            int row = rank + i, col = file;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WROOK && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BROOK && side == WHITE) attackers.push_back(index);
            if(board[row][col] == WQUEEN && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BQUEEN && side == WHITE) attackers.push_back(index);
            break;
        }
    }
    for(int i = -1;i>=(-rank);i--){
        if(!isValid(rank + i, file)) continue;
        if(board[rank + i][file] != EMPTY && board[rank + i][file] != OCCUPIED){
            int row = rank + i, col = file;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WROOK && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BROOK && side == WHITE) attackers.push_back(index);
            if(board[row][col] == WQUEEN && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BQUEEN && side == WHITE) attackers.push_back(index);
            break;
        }
    }
    for(int i = 0;i<(8-file);i++){
        if(!isValid(rank, file + i)) continue;
        if(board[rank][file + i] != EMPTY && board[rank][file + i] != OCCUPIED){
            int row = rank, col = file + i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WROOK && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BROOK && side == WHITE) attackers.push_back(index);
            if(board[row][col] == WQUEEN && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BQUEEN && side == WHITE) attackers.push_back(index);
            break;
        }
    }
    for(int i = -1;i>=(-file);i--){
        if(!isValid(rank, file + i)) continue;
        if(board[rank][file + i] != EMPTY && board[rank][file + i] != OCCUPIED){
            int row = rank, col = file + i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WROOK && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BROOK && side == WHITE) attackers.push_back(index);
            if(board[row][col] == WQUEEN && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BQUEEN && side == WHITE) attackers.push_back(index);
            break;
        }
    }
    if(side == BLACK){
        if(isValid(rank, file+1) && board[rank][file+1] == WKING) attackers.push_back((Square)((rank)*8 + (file+1)));
        if(isValid(rank, file-1) && board[rank][file-1] == WKING) attackers.push_back((Square)((rank)*8 + (file-1)));
        if(isValid(rank+1, file) && board[rank+1][file] == WKING) attackers.push_back((Square)((rank+1)*8 + (file)));
        if(isValid(rank-1, file) && board[rank-1][file] == WKING) attackers.push_back((Square)((rank-1)*8 + (file)));
    }
    else{
        if(isValid(rank, file+1) && board[rank][file+1] == BKING) attackers.push_back((Square)((rank)*8 + (file+1)));
        if(isValid(rank, file-1) && board[rank][file-1] == BKING) attackers.push_back((Square)((rank)*8 + (file-1)));
        if(isValid(rank+1, file) && board[rank+1][file] == BKING) attackers.push_back((Square)((rank+1)*8 + (file)));
        if(isValid(rank-1, file) && board[rank-1][file] == BKING) attackers.push_back((Square)((rank-1)*8 + (file)));
    }
    return attackers;
}

std::vector<Square> Board::L(const Square& pos,const Color& side){
    std::vector<Square> attackers;
    int file = pos%8, rank = pos/8, count = 0;
    for(int i = -1;i<1;i++){
        if(i == 0) continue;
        if(isValid(rank + i, file + 2*i) && board[rank + i][file + 2*i] != EMPTY && board[rank + i][file + 2*i] != OCCUPIED){
            int row = rank + i, col = file + 2*i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WKNIGHT && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BKNIGHT && side == WHITE) attackers.push_back(index);
        }
        if(isValid(rank + 2*i, file + i) && board[rank + 2*i][file + i] != EMPTY && board[rank + 2*i][file + i] != OCCUPIED){
            int row = rank + 2*i, col = file + i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WKNIGHT && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BKNIGHT && side == WHITE) attackers.push_back(index);
        }
    }
    for(int i = -1;i<1;i++){
        if(i == 0) continue;
        if(isValidIndex(rank + 2*i, file - i) && board[rank + 2*i][file - i] != EMPTY && board[rank + 2*i][file - i] != OCCUPIED){
            int row = rank + 2*i, col = file - i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WKNIGHT && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BKNIGHT && side == WHITE) attackers.push_back(index);
        }
        if(isValidIndex(rank + i, file - 2*i) && board[rank + i][file - 2*i] != EMPTY && board[rank + i][file - 2*i] != OCCUPIED){
            int row = rank + i, col = file - 2*i;
            Square index = (Square)(row*8 + col);
            if(board[row][col] == WKNIGHT && side == BLACK) attackers.push_back(index);
            if(board[row][col] == BKNIGHT && side == WHITE) attackers.push_back(index);
        }
    }
    return attackers;
}

PieceType BoardUtils::what_piece(const Pieces& piece){
    if(piece == WPAWN || piece == BPAWN) return PAWN;
    else if(piece == WROOK || piece == BROOK) return ROOK;
    else if(piece == WKNIGHT || piece == BKNIGHT) return KNIGHT;
    else if(piece == WBISHOP || piece == BBISHOP) return BISHOP;
    else if(piece == WQUEEN || piece == BQUEEN) return QUEEN;
    else if(piece == WKING || piece == BKING) return KING;
    else return NILL;
}

bool BoardUtils::isChessPiece(const Pieces& piece){
    if(piece == EMPTY || piece == OCCUPIED || piece == OCCUPIEDPIECE) return false;
    return true;
}

bool BoardUtils::isSameColor(const Pieces& piece1, const Pieces& piece2){
    if(!isChessPiece(piece1) || !isChessPiece(piece2)) return false;
    if(piece1%2 == piece2%2) return true;
}

bool BoardUtils::isLegalMoveRook(const Move& move){
    int file1 = move.from%8, rank1 = move.from/8, file2 = move.to%8, rank2 = move.to/8;
    if(rank1 != rank2 && file1 != file2) return false;
    return true;
}

bool BoardUtils::isLegalMoveBishop(const Move& move){
    int file1 = move.from%8, rank1 = move.from/8, file2 = move.to%8, rank2 = move.to/8;
    if((rank2 - rank1 != file2 - file1) && (rank2 - rank1 != file1 - file2)) return false;
    return true;
}

bool BoardUtils::isLegalMoveKnight(const Move& move){
    int file1 = move.from%8, rank1 = move.from/8, file2 = move.to%8, rank2 = move.to/8;
    int index1 = mod(rank2 - rank1), index2 = mod(file2 - file1);
    if(index1 != 2*index2 && index2 != 2*index1) return false;
    return true;
}

bool BoardUtils::isLegalMoveQueen(const Move& move){
    bool check1 = isLegalMoveBishop(move), check2 = isLegalMoveRook(move);
    if(check1 || check2) return true;
}

bool BoardUtils::isLegalMoveKing(const Move& move){
    int file1 = move.from%8, rank1 = move.from/8, file2 = move.to%8, rank2 = move.to/8;
    int diff1 = mod(file2 - file1), diff2 = mod(rank2 - rank1);
    if(diff1 != 1 && diff2 != 1 && !move.isCastle) return false;
    if(move.isCastle){
        if((rank1 != 0 || rank2 != 0) && (rank1 != 7 || rank2 != 7)) return false;
        if(diff1 != 2) return false;
    }
    return true;
}

bool BoardUtils::isLegalMovePawn(const Move& move, const Color& side){
    int file1 = move.from%8, rank1 = move.from/8, file2 = move.to%8, rank2 = move.to/8, diff1 = file2-file1, diff2 = rank2 - rank1;
    if(side == WHITE){
        if(diff2 != -1) return false;
        if(diff1 != -1 && diff1 != -1 && diff1 != 0) return false;
        return true;
    }
    else{
        if(diff2 != 1) return false;
        if(diff1 != -1 && diff1 != -1 && diff1 != 0) return false;
        return true;
    }
    return false;
}

//Constructors Definition

Board::Board(){
    this->board = Default_Board;
    this->sideToMove = WHITE;
    this->castlingRights = Default_Rights;
    this->enPassantSquare = NO_SQUARE;
    this->prev_move = MoveState();
    this->BlackKing = E1;
    this->WhiteKing = E8;
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

bool Board::isValid(int row, int col){
    if(row >= 8 || row < 0) return false;
    if(col >= 8 || col < 0) return false;
    return true;
}

//Occupied function supporters

int Board::Occupied_King(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos){
    int position = pos, file = pos%8, rank = pos/8, count = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            if(!isValid(rank + i, file + j)) continue;
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
        if(!isValid(rank + i, file)) continue;
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
        if(!isValid(rank + i, file)) continue;
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
        if(!isValid(rank, file + i)) continue;
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
        if(!isValid(rank, file + i)) continue;
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
        if(!isValid(rank+i, file+i)) continue;
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
        if(!isValid(rank-i, file-i)) continue;
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
        if(!isValid(rank+i, file-i)) continue;
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
        if(!isValid(rank-i, file+i)) continue;
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
        if(isValid(rank + i, file + 2*i) && board[rank + i][file + 2*i] != EMPTY && board[rank + i][file + 2*i] != OCCUPIED){
            board_occupied[rank+i][file+2*i] = OCCUPIEDPIECE;
        }
        if(isValid(rank + 2*i, file + i) && board[rank + 2*i][file + i] != EMPTY && board[rank + 2*i][file + i] != OCCUPIED){
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
        if(isValid(rank + 2*i, file - i) && board[rank + 2*i][file - i] != EMPTY && board[rank + 2*i][file - i] != OCCUPIED){
            board_occupied[rank + 2*i][file - i] = OCCUPIEDPIECE;
        }
        if(isValid(rank + i, file - 2*i) && board[rank + i][file - 2*i] != EMPTY && board[rank + i][file - 2*i] != OCCUPIED){
            board_occupied[rank+i][file - 2*i] = OCCUPIEDPIECE;
        }
    }
    if(!count){
        return 0;
    }
    return 1;
}

int Board::Occupied_Pawn(std::array<std::array<Pieces, 8>, 8>& board_occupied, const Square& pos, int side){
    int file = pos%8, rank = pos/8, count = 0;
    if(!side){
        side = -1;
    }
    for(int i = -1;i<1;i++){
        if(i==0) continue;
        if(!isValid(rank + side, file + i)) continue;
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

std::array<std::array<Pieces, 8>, 8> Board::Occupied(int side){
    std::array<std::array<Pieces, 8>, 8> board_occupied;
    board_occupied = board;
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board[i][j]%2 == 1 && side == 0){
                Square pos = (Square)(i*8+j);
                switch(board[i][j]){
                    case WPAWN:
                        Occupied_Pawn(board_occupied, pos, side);
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
                        Occupied_Pawn(board_occupied, pos, side);
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

//Attackers function

std::vector<Square> Board::Attackers(const Square& pos, Color side){
    std::vector<Square> attackers = Cross(pos, side);
    std::vector<Square> plus_attackers = Plus(pos, side);
    std::vector<Square> L_attackers = L(pos, side);
    attackers.insert(attackers.end(), plus_attackers.begin(), plus_attackers.end());
    attackers.insert(attackers.end(), L_attackers.begin(), L_attackers.end());
    return attackers;
}

//check funtions

bool Board::isEnpassant(const Square& pos1, const Square& pos2){
    int file1 = pos1%8, file2 = pos2%8, rank1 = pos1/8, rank2 = pos2/8;
    if(enPassantSquare == NO_SQUARE) return false;
    if((!isValid(rank1, file1)) || (!isValid(rank2, file2))) return false;
    if(rank1 != rank2) return false;
    if(file1 != file2 - 1 && file2 != file1 - 1) return false;
    if(board[rank1][file1] == WPAWN && board[rank2][file2] == BPAWN){
        Square index1 = (Square)((file1) + 8*(rank1+1)), index2 = (Square)((file2) + 8*(rank2-1));
        if(enPassantSquare == index1 || enPassantSquare == index2) return true;
    }
    else if(board[rank1][file1] == BPAWN && board[rank2][file2] == WPAWN){
        Square index1 = (Square)((file1) + 8*(rank1-1)), index2 = (Square)((file2) + 8*(rank2+1));
        if(enPassantSquare == index1 || enPassantSquare == index2) return true;
    }
    return false;
}


bool Board::ischeck(){
    std::vector<Square> attackers;
    if(sideToMove == BLACK){
        attackers = Attackers(BlackKing, BLACK);
    }
    else{
        attackers = Attackers(WhiteKing, WHITE); 
    }
    if(attackers.size() == 0){
        return false;
    }
    return true;
}

bool Board::ischeckmate(){
    std::vector<Square> attackers;
    std::array<std::array<Pieces, 8>, 8> board_occupied = Occupied(sideToMove);
    if(sideToMove == BLACK){
        attackers = Attackers(BlackKing, BLACK);
    }
    else{
        attackers = Attackers(WhiteKing, WHITE);
    }
    if(attackers.size() == 0) return false;
    if(attackers.size() > 1){
        int file, rank;
        if(sideToMove == WHITE){
            file = WhiteKing%8, rank = WhiteKing/8;
        }
        else{
            file = BlackKing%8, rank = BlackKing/8;
        }
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if(board_occupied[i][j] == EMPTY || (board_occupied[i][j] != OCCUPIED && board_occupied[i][j] != OCCUPIEDPIECE && board_occupied[i][j]%2 != sideToMove)){
                    return false;
                }
            }
        }
        return true;
    }
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board_occupied[i][j] == EMPTY || (board_occupied[i][j] != OCCUPIED && board_occupied[i][j] != OCCUPIEDPIECE && board_occupied[i][j]%2 != sideToMove)){
                return false;
            }
        }
    }
    std::vector<Square> defenders;
    if(sideToMove == BLACK){
        defenders = Attackers(attackers[0], WHITE);
    }
    else{
        defenders = Attackers(attackers[0], BLACK);
    }
    if(defenders.size() >= 1) return false;
    return true;
}

bool Board::isstalemate(){
    std::vector<Square> attackers;
    int file, rank, side;
    if(sideToMove == BLACK){
        attackers = Attackers(BlackKing, BLACK);
        file = BlackKing%8, rank = BlackKing/8;
        side = 1;
    }
    else{
        attackers = Attackers(WhiteKing, WHITE);
        file = WhiteKing%8, rank = WhiteKing/8;
        side = 0;
    }
    if(attackers.size() >= 1) return false;

    std::array<std::array<Pieces, 8>, 8> board_occupied = Occupied((int)sideToMove);

    for(int i = -1;i<=1;i++){
        for(int j = -1;j<=1;j++){
            if(i == 0 && j == 0) continue;
            if(!isValid(i, j))
            if(board_occupied[rank+i][file+j] == EMPTY || board_occupied[rank+i][file+j]%2 == side) return false;
        }
    }

    board_occupied = Occupied(!((int)sideToMove));
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board_occupied[i][j] == WKING && sideToMove == WHITE) continue;
            if(board_occupied[i][j] == BKING && sideToMove == BLACK) continue;
            if(board_occupied[i][j] == OCCUPIED || board_occupied[i][j] == OCCUPIEDPIECE){
                if(board[i][j]%2 == 0 && sideToMove == WHITE) continue;
                if(board[i][j]%2 == 1 && sideToMove == BLACK) continue;
                if(board[i][j] == WPAWN){
                    if(board[i-1][j] != EMPTY) continue;
                }
                if(board[i][j] == BPAWN){
                    if(board[i+1][j] != EMPTY) continue;
                }
                return false;
            }
        }
    }

    for(int i = 3;i<=4;i++){
        for(int j = 0;j<7;j++){
            Square index1 = Square(8*i + j), index2 = Square(8*i + j + 1);
            if(isEnpassant(index1, index2)){
                return false;
            }
        }
    }

    if(sideToMove == BLACK){
        if(castlingRights & BLACK_KINGSIDE){
            if(board[0][5] == EMPTY && board[0][6] == EMPTY) return false;
        }
        if(castlingRights & BLACK_QUEENSIDE){
            if(board[0][1] == EMPTY && board[0][2] == EMPTY && board[0][3] == EMPTY) return false;
        }
    }
    else{
        if(castlingRights & WHITE_KINGSIDE){
            if(board[7][5] == EMPTY && board[7][6] == EMPTY) return false;
        }
        if(castlingRights & WHITE_QUEENSIDE){
            if(board[7][1] == EMPTY && board[7][2] == EMPTY && board[7][3] == EMPTY) return false;
        }
    }

    return true;
}

//Legal Move

Board Board::movePiece(const Move& move){
    Board new_board = *this;
    int file1 = move.from%8, rank1 = move.from/8, file2 = move.to%8, rank2 = move.to/8;
    if(move.isCastle){
        if(board[rank1][file1]%2 == WHITE){
            new_board.board[rank2][file2] = WKING;
            new_board.board[rank1][file1] = EMPTY;
            if(castlingRights & WHITE_KINGSIDE){
                new_board.board[rank1][file1 + 1] = WROOK;
                new_board.board[rank2][file2 + 1] = EMPTY;
            }
            else{
                new_board.board[rank1][file1-1] = WROOK;
                new_board.board[rank2][file2 - 2] = EMPTY;
            }
            new_board.castlingRights &= ~WHITE_KINGSIDE;
            new_board.castlingRights &= ~WHITE_QUEENSIDE;
        }
        else{
            new_board.board[rank2][file2] = BKING;
            new_board.board[rank1][file1] = EMPTY;
            if(castlingRights & BLACK_KINGSIDE){
                new_board.board[rank1][file1 + 1] = BROOK;
                new_board.board[rank2][file2 + 1] = EMPTY;
            }
            else{
                new_board.board[rank1][file1-1] = BROOK;
                new_board.board[rank2][file2 - 2] = EMPTY;
            }
            new_board.castlingRights &= ~BLACK_KINGSIDE;
            new_board.castlingRights &= ~BLACK_QUEENSIDE;
        }
        return new_board;
    }
    if(move.isEnPassant){
        new_board.board[rank1][file1] = EMPTY;
        new_board.board[rank2][file2] = board[rank1][file1];
        new_board.board[rank1][file2] = EMPTY; 
    }
    if(move.promotion != NILL){
        switch (move.promotion)
        {
        case ROOK:
            new_board.board[rank1][file1] = EMPTY;
            if(board[rank1][file1]%2 == WHITE){
                new_board.board[rank2][file2] = WROOK;
            }
            else{
                new_board.board[rank2][file2] = BROOK;
            }
            break;
        
        case KNIGHT:
            new_board.board[rank1][file1] = EMPTY;
            if(board[rank1][file1]%2 == WHITE){
                new_board.board[rank2][file2] = WKNIGHT;
            }
            else{
                new_board.board[rank2][file2] = BKNIGHT;
            }
            break;
        case BISHOP:
            new_board.board[rank1][file1] = EMPTY;
            if(board[rank1][file1]%2 == WHITE){
                new_board.board[rank2][file2] = WBISHOP;
            }
            else{
                new_board.board[rank2][file2] = BBISHOP;
            }
            break;
        case QUEEN:
            new_board.board[rank1][file1] = EMPTY;
            if(board[rank1][file1]%2 == WHITE){
                new_board.board[rank2][file2] = WQUEEN;
            }
            else{
                new_board.board[rank2][file2] = BQUEEN;
            }
        }
        return new_board;
    }
    new_board.board[rank1][file1] = EMPTY;
    new_board.board[rank2][file2] = board[rank1][file1];
    return new_board;
}

bool Board::isLegalMove(const Move& move){
    if(move.isCastle && move.isEnPassant) return false;
    int file1 = move.from%8, rank1 = move.from/8, file2 = move.to%8, rank2 = move.to/8;
    if(!isValid(rank1, file1)) return false;
    if(!isValid(rank2, file2)) return false;
    if(board[rank1][file1] == EMPTY) return false;
    if((board[rank1][file1]%2 != sideToMove || (board[rank2][file2] != EMPTY && board[rank2][file2]%2 == sideToMove))) return false;
    if(move.isCastle){
        if(board[rank1][file1] != WKING) 
        if(sideToMove == WHITE && (!(castlingRights & WHITE_KINGSIDE)) && (!(castlingRights & WHITE_QUEENSIDE))) return false;
        if(sideToMove == BLACK && (!(castlingRights & BLACK_KINGSIDE)) && (!(castlingRights & BLACK_QUEENSIDE))) return false;
        if(sideToMove == WHITE){
            if(rank1 != rank2) return false;
            if(rank1 != 7) return false;
            if(castlingRights & WHITE_KINGSIDE){
                if(board[7][6] != EMPTY || board[7][5] != EMPTY) return false;
                if(file2 != 6) return false;
            }
            else{
                if(board[7][3] != EMPTY || board[7][2] != EMPTY || board[7][1] != EMPTY) return false;
                if(file2 != 2) return false;
            }
        }
        else{
            if(rank1 != rank2) return false;
            if(rank1 != 0) return false;
            if(castlingRights & WHITE_KINGSIDE){
                if(board[0][6] != EMPTY || board[0][5] != EMPTY) return false;
                if(file2 != 6) return false;
            }
            else{
                if(board[0][3] != EMPTY || board[0][2] != EMPTY || board[0][1] != EMPTY) return false;
                if(file2 != 2) return false;
            }
        }
    }
    else if(move.isEnPassant){
        if(enPassantSquare == NO_SQUARE) return false;
        Square next1, next2;
        if(sideToMove == WHITE){
            next1 = Square((rank1-1)*8 + file1 + 1);
            next2 = Square((rank1-1)*8 + file1 - 1);
        }
        else{
            next1 = Square((rank1 + 1) * 8 + file1 + 1);
            next2 = Square((rank1 + 1)*8 + file1 - 1);
        }
        if(enPassantSquare != next1 && enPassantSquare != next2) return false;
    }
    else if(move.promotion != NILL){
        if(sideToMove == WHITE){
            if(rank2 - rank1 != -1) return false;
        }
        else{
            if(rank2 - rank1 != 1) return false;
        }
        if(move.promotion == KING) return false;
        if(board[rank2][file2] != EMPTY) return false;
    }
    Board new_board = movePiece(move);
    switch (BoardUtils::what_piece(board[file1][rank1]))
    {
    case ROOK:
        if(!BoardUtils::isLegalMoveRook(move)) return false;
        break;
    
    case BISHOP:
        if(!BoardUtils::isLegalMoveBishop(move)) return false;
        break;
    
    case KNIGHT:
        if(!BoardUtils::isLegalMoveKnight(move)) return false;
        break;

    case QUEEN:
        if(!BoardUtils::isLegalMoveQueen(move)) return false;
        break;
    
    case KING:
        if(!BoardUtils::isLegalMoveKing(move)) return false;
        break;

    case PAWN:
        if(!BoardUtils::isLegalMovePawn(move, sideToMove)) return false;
        break;
    
    default:
        break;
    }
    if(new_board.ischeck()) return false;
    return true;
}

//Generate Move functions

std::vector<Move> Board::generateMovesBishop(const Square& pos){
    std::vector<Move> moves;
    int file = pos%8, rank = pos/8, count = 0, URlimit = (rank > file)?(8-rank):(8-file), LLlimit = (rank > file)?file:rank, ULlimit = (rank + file < 8)?file: (8 - rank), LRlimit = (rank+file < 8)?rank:(8-file);
    for(int i = 1;i<URlimit;i++){
        if(!isValid(rank+i, file+i)) continue;
        if(isValidIndex(rank+i, file+i)){
            count++;
        }
        if(BoardUtils::isChessPiece(board[rank+i][file+i])){
            if(!BoardUtils::isSameColor(board[rank+i][file+i], board[rank][file])){
            }
            break;
        }
    }
    for(int i = 1;i<=LLlimit;i++){
        if(!isValid(rank-i, file-i)) continue;
        if(isValidIndex(rank-i, file-i)){
            count++;
        }
        if(board[rank-i][file-i] != EMPTY && board[rank-i][file-i] != OCCUPIED){
            break;
        }
    }
    for(int i = 1;i<=ULlimit;i++){
        if(!isValid(rank+i, file-i)) continue;
        if(isValidIndex(rank+i, file-i)){
            count++;
        }
        if(board[rank+i][file-i] != EMPTY && board[rank+i][file-i] != OCCUPIED){
            break;
        }
    }
    for(int i = 1;i <= LRlimit;i++){
        if(!isValid(rank-i, file+i)) continue;
        if(isValidIndex(rank-i, file+i)){
            count++;
        }
        if(board[rank-i][file+i] != EMPTY && board[rank-i][file+i] != OCCUPIED){
            break;
        }
    }
}

std::vector<Move> Board::generateMovesPiece(const Square& pos){

}