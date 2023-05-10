#ifndef __COORDINATES__
#define __COORDINATES__
#include <cmath>

enum Color{white, black};

int offset(int x, int y) {
    return abs(x - y);
}

struct Coordinates {
    int row, column;

    Coordinates(const int row, const int column): 
        row(row), column(column) {}

    Coordinates(const int row, const char column):
        row(row), column(column - 'a' + 1) {}

    int column_offset(const Coordinates& other) const {
        return offset(column, other.column);
    }

    int row_offset(const Coordinates& other) const {
        return offset(row, other.row);
    }

    bool same_column(const Coordinates& other) const {
        return (column == other.column);
    }

    bool same_row(const Coordinates& other) const {
        return (row == other.row);
    }

    bool one_offset(const Coordinates& other) const {
        return (row_offset(other) <= 1 && column_offset(other) <= 1);
    }

    bool forward(const Coordinates& other, const Color& color) const {
        return (color == Color::white) ? (row < other.row) : (other.row < row);
    }

    bool diagonal(const Coordinates& other) const {
        return (row_offset(other) == column_offset(other));
    }

    bool knight_move(const Coordinates& other) const {
        int row_diff = row_offset(other);
        int column_diff = column_offset(other);
        return ((row_diff == 2 && column_diff == 1) || (row_diff == 1 && column_diff == 2));
        // return (row_diff != 0 && column_diff != 0 && row_diff + column_diff == 3);
    }
};

#endif // __COORDINATES__
