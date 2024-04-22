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

    // Initializing the players
    Player player1{};
    Player player2{};

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

        // Paddle Movement Logic
        if (IsKeyDown(KEY_D))
        {
            paddle1.y -= paddle1.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_F))
        {
            paddle1.y += paddle1.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_J))
        {
            paddle2.y -= paddle2.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_K))
        {
            paddle2.y += paddle2.speed * GetFrameTime();
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