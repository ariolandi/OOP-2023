#include <iostream>
#include <vector>
#include "pawn.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"
using std::cout, std::endl, std::vector;

int main(){
    Pawn p(1, 4, white);
    ChessSquare s(2, 4);
    // cout << s1.forward(s, white) << " " << s1.one_offset(s) << " " << s.has_piece << " " << s1.same_column(s) << endl;
    p.move(s);

    Pawn p1(3, 5, black);
    ChessSquare s1(3, 5);
    s1.has_piece = &p1;
    p.move(s1);

    return 0;
}