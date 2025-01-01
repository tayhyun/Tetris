#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"
int main()
{
   Color darkBlue = {44, 44, 127, 255};
   InitWindow(300, 600, "Tetris by Tae");
   SetTargetFPS(60);

   Grid grid = Grid();
   TBlock block = TBlock();
   grid.Print();

   while (WindowShouldClose() == false)
   {
      BeginDrawing();
      ClearBackground(darkBlue);
      grid.Draw();
      block.Draw();
      EndDrawing();
   }
}