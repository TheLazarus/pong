#include <iostream>
#include "raylib.h"

int main()
{
    std::cout << "Welcome to Pong! \n";
    InitWindow(800, 600, "Pong!");

    SetWindowState(FLAG_VSYNC_HINT);

    float ballX = GetScreenWidth() / 2.0f, ballY = GetScreenHeight() / 2.0f;
    float ballRadius = 5;
    float paddle1X = 0, paddle2X = 0, paddle1Y = 0, paddle2Y = 0;
    float ballSpeedX = 50.0f;
    float ballSpeedY = 50.0f;

    std::cout << ballX << ballY;
    std::cout << paddle1X << paddle2X << paddle2Y << paddle1Y;

    // Game Loop
    while (!WindowShouldClose())
    {
        
        // Game Update Logic
        ballX += ballSpeedX * GetFrameTime();
        ballY += ballSpeedY * GetFrameTime();


        // Rendering Logic
        BeginDrawing();

        ClearBackground(BLACK);
        DrawFPS(10, 10);

        DrawCircle((int)ballX, (int)ballY, ballRadius, WHITE);
        DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, RED);
        DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}