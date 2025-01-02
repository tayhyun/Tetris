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
    int grid[20][10];

private:
    int mNumRows;
    int mNumCols;
    int mCellSize;
    std::vector<Color> colors;
};