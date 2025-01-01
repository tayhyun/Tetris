#include "grid.h"
#include "iostream"

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
std::vector<Color> Grid::GetCellColors()
{
    const Color darkGrey = {26, 31, 40, 255};
    const Color green = {47, 230, 23, 255};
    const Color red = {232, 18, 18, 255};
    const Color orange = {226, 116, 17, 255};
    const Color yellow = {237, 234, 4, 255};
    const Color purple = {166, 0, 247, 255};
    const Color cyan = {21, 204, 209, 255};
    const Color blue = {13, 64, 216, 255};
    const Color lightBlue = {59, 85, 162, 255};
    const Color darkBlue = {44, 44, 127, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue, lightBlue, darkBlue};
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