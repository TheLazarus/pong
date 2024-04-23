#include <iostream>
#include "raylib.h"

struct Ball
{
    float x, y;
    float speedX, speedY;
    int radius;

    void draw()
    {
        DrawCircle((int)x, (int)y, radius, WHITE);
    }
};

struct Paddle
{
    float x, y, speed;
    float width, height;

    Rectangle GetRect()
    {
        return Rectangle{x - width / 2, y - height / 2, width, height};
    }

    void draw()
    {
        DrawRectangleRec(GetRect(), WHITE);
    }
};

struct Player
{
    int points;
};

int main()
{
    std::cout << "Welcome to Pong! \n";
    InitWindow(800, 600, "Pong!");

    SetWindowState(FLAG_VSYNC_HINT);

    // Initializing the ball state

    Ball ball{
        .x{GetScreenWidth() / 2.0f},
        .y{GetScreenHeight() / 2.0f},
        .speedX{200.0f},
        .speedY{200.0f},
        .radius{5},
    };

    // Initializing the paddles
    Paddle paddle1{.x{50.0f}, .y{GetScreenHeight() / 2.0f}, .speed{400}, .width{10}, .height{100}};
    Paddle paddle2{.x{GetScreenWidth() - 50.0f}, .y{GetScreenHeight() / 2}, .speed{400}, .width{10}, .height{100}};

    // Game Loop
    while (!WindowShouldClose())
    {

        // Game Over Logic

        if (ball.x < paddle1.x)
        {
            std::cout << "Game Over For Player 1";
        }

        if (ball.x > paddle2.x + paddle2.width)
        {
            std::cout << "Game Over For Player 2";
        }

        // Ball Movement Logic
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        // Paddle Movement Logic
        if (IsKeyDown(KEY_D) && paddle1.y - paddle1.height / 2 > 0)
        {
            paddle1.y -= paddle1.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_F) && (paddle1.y + paddle1.height / 2) < GetScreenHeight())
        {
            paddle1.y += paddle1.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_J) && paddle2.y - paddle2.height / 2 > 0)
        {
            paddle2.y -= paddle2.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_K) && (paddle2.y + paddle2.height / 2) < GetScreenHeight())
        {
            paddle2.y += paddle2.speed * GetFrameTime();
        }

        // Paddle and Ball Collision Logic
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, paddle1.GetRect()) && ball.speedX < 0)
        {
            ball.speedX *= -1.1f;
        }

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, paddle2.GetRect()) && ball.speedX > 0)
        {
            ball.speedX *= -1.1f;
        }

        // Boundary Collisions

        if (ball.y < 0 || ball.y >= GetScreenHeight())
        {
            ball.speedY *= -1;
        }

        if (ball.x < 0 || ball.x > GetScreenWidth())
        {

            ball.speedX *= -1;
        }

        // Rendering
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Welcome to Pong!", 50, 50, 30, RED);
        DrawFPS(10, 10);

        paddle1.draw();
        paddle2.draw();
        ball.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}