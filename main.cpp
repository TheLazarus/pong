#include <iostream>
#include "raylib.h"

struct Ball
{
    float x{}, y{};
    float speedX{}, speedY{};
    float radius{};

    void draw()
    {
        DrawCircle((int)x, (int)y, radius, WHITE);
    }
};

int main()
{
    std::cout << "Welcome to Pong! \n";
    InitWindow(800, 600, "Pong!");

    SetWindowState(FLAG_VSYNC_HINT);

    // Initializing the ball state
    Ball ball{};
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.radius = 5.0f;
    ball.speedX = 200.0f;
    ball.speedY = 200.0f;

    // Game Loop
    while (!WindowShouldClose())
    {

        // Ball Movement and Boundary Collision Logic
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        if (ball.y < 0 || ball.y >= GetScreenHeight())
        {
            ball.speedY *= -1;
        }

        if (ball.x < 0 || ball.x > GetScreenWidth())
        {

            ball.speedX *= -1;
        }

        // Rendering
        // Game updates should be made before the BeginDrawing() call
        BeginDrawing();

        ClearBackground(BLACK);
        DrawFPS(10, 10);

        DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, RED);
        DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, RED);
        ball.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}