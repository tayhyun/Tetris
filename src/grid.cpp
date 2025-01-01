#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    mNumRows = 20;
    mNumCols = 10;
    mCellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    for (int row = 0; row < mNumRows; row++)
    {
        for (int column = 0; column < mNumCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}
void Grid::Print()
{
    for (int row = 0; row < mNumRows; row++)
    {
        for (int column = 0; column < mNumCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }

        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for (int row = 0; row < mNumRows; row++)
    {

        for (int column = 0; column < mNumCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * mCellSize + 1, row * mCellSize + 1, mCellSize - 1, mCellSize - 1, colors[cellValue]);
        }
    }
}