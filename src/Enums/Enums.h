#pragma once

#include <iostream>
#include <array>

#define cat(a, b) (a+b)
#define sub(a, b) (a-b)


using CastlingRights = u_int8_t;
using Hashing = u_int64_t;

enum Square{
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,

    NO_SQUARE
};

enum Pieces{
    EMPTY,
    OCCUPIED,
    WPAWN,
    BPAWN,
    WROOK,
    BROOK,
    WKNIGHT,
    BKNIGHT,
    WBISHOP,
    BBISHOP,
    WQUEEN,
    BQUEEN,
    WKING,
    BKING,
    OCCUPIEDPIECE
};

enum Color{
    WHITE,
    BLACK
};

enum Rights{
    WHITE_KINGSIDE = 1,
    WHITE_QUEENSIDE = 2,
    BLACK_KINGSIDE = 4,
    BLACK_QUEENSIDE = 8
};

enum PieceType{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    NILL
};

std::array<std::array<Pieces, 8>, 8> Default_Board{{
    {BROOK, BKNIGHT, BBISHOP, BQUEEN, BKING, BBISHOP, BKNIGHT, BROOK},
    {BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN},
    {WROOK, WKNIGHT, WBISHOP, WQUEEN, WKING, WBISHOP, WKNIGHT, WROOK}
}};

CastlingRights Default_Rights = WHITE_KINGSIDE || WHITE_QUEENSIDE || BLACK_KINGSIDE || BLACK_QUEENSIDE;
