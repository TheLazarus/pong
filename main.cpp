#include <iostream>
#include "raylib.h"

struct Ball
{
    float x, y, speedX, speedY;
    int radius;

    void draw()
    {
        DrawCircle((int)x, (int)y, radius, WHITE);
    }
};

struct Paddle
{
    float x, y, speed;
    int width, height;

    void draw()
    {
        DrawRectangle(x, y, width, height, RED);
    }
};

struct Player
{
    int points;
};

void initializeWindow()
{
    ClearBackground(BLACK);
    DrawText("Welcome to Pong!", 50, 50, 30, RED);
    DrawFPS(10, 10);
}

int main()
{
    std::cout << "Welcome to Pong! \n";
    InitWindow(800, 600, "Pong!");

    SetWindowState(FLAG_VSYNC_HINT);

    // Initializing the ball state
    Ball ball{};
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.radius = 5;
    ball.speedX = 200.0f;
    ball.speedY = 200.0f;

    // Initializing the paddles
    Paddle paddle1{.x{50.0f}, .y{GetScreenHeight() / 2.0f - 50.0f}, .speed{400}, .width{10}, .height{100}};
    Paddle paddle2{.x{GetScreenWidth() - 50 - 10}, .y{GetScreenHeight() / 2 - 50}, .speed{400}, .width{10}, .height{100}};

    // Game Loop
    while (!WindowShouldClose())
    {

        // Ball and Paddle Movement Logic
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        if (IsKeyDown(KEY_D) && paddle1.y > 0)
        {
            paddle1.y -= paddle1.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_F) && (paddle1.y + paddle1.height) < GetScreenHeight())
        {
            paddle1.y += paddle1.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_J) && paddle2.y > 0)
        {
            paddle2.y -= paddle2.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_K) && (paddle2.y + paddle2.height) < GetScreenHeight())
        {
            paddle2.y += paddle2.speed * GetFrameTime();
        }

        // Ball and Paddle Collision Logic

        if (ball.y < 0 || ball.y >= GetScreenHeight())
        {
            ball.speedY *= -1;
        }

        if (ball.x < 0 || ball.x > GetScreenWidth())
        {

            ball.speedX *= -1;
        }

        // Game Over Logic

        if (ball.x < paddle1.x)
        {
            std::cout << "Game Over For Player 1";
        }

        if (ball.x > paddle2.x + paddle2.width)
        {
            std::cout << "Game Over For Player 2";
        }

        // Rendering
        // Game updates should be made before the BeginDrawing() call
        BeginDrawing();
        initializeWindow();
        paddle1.draw();
        paddle2.draw();
        ball.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}