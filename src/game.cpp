#include "game.h"
#include <random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase((blocks.begin()) + randomIndex);
    return block;
}
std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_D:
        MoveBlockRight();
        break;
    case KEY_A:
        MoveBlockLeft();
        break;
    case KEY_S:
        MoveBlockDown();
        break;
    }
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
}
void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
}