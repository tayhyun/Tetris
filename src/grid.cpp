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

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < mNumRows && column >= 0 && column < mNumCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int complete = 0;

    for (int row = mNumRows - 1; row >= 0; row--)
    {
        if (isRowFull(row))
        {
            clearRow(row);
            complete++;
        }
        else if (complete > 0)
        {
            moveRowDown(row, complete);
        }
    }
    return complete;
}

bool Grid::isRowFull(int row)
{
    for (int column = 0; column < mNumCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row)
{
    for (int column = 0; column < mNumCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::moveRowDown(int row, int numRows)
{
    for (int column = 0; column < mNumCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
