#include <iostream>
#include "raylib.h"

int main()
{
    std::cout << "Welcome to Pong! \n";
    InitWindow(800, 600, "Pong!");

    while (!WindowShouldClose())
    {
        // Game Loop
    }

    CloseWindow();
    return 0;
}