#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
    int grid[20][10];

private:
    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowDown(int row, int numRows);
    int mNumRows;
    int mNumCols;
    int mCellSize;
    std::vector<Color> colors;
};