#include <iostream>  // Library for printing text to the console
#include <raylib.h>  // The main raylib library for graphics and windows
#include <deque>
#include <raymath.h>

using namespace std; // Allows us to use names like 'cout' without typing 'std::'

// Define custom colors using RGBA (Red, Green, Blue, Alpha/Opacity)
Color green = {173, 204, 96, 255};      // Light green for the background
Color darkGreen = {43, 51, 24, 255};    // Dark green for the food

// Grid settings: The game is played on a grid of squares
int cellSize = 30;  // Each square (cell) is 30 pixels wide and 30 pixels high
int cellCount = 25; // There are 25 squares across and 25 squares down

class Snake{
    public:
        deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
        Vector2 direction = {1,  0};

        void Draw()
        {
            for(unsigned int i=0; i< body.size(); i++)
            {
                float x = body[i].x;
                float y = body[i].y;
                Rectangle segment = Rectangle{x*cellSize, y*cellSize, (float)cellSize, (float)cellSize};
                DrawRectangleRounded(segment, 0.5, 6, darkGreen);
            }
        }
    
    void Update()
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));
    }    
};
// The Food class: A blueprint for how food behaves and looks
class Food {

    public:
    // Vector2 is a raylib type that stores an X and a Y value
    // Here, we set the food to be at column 5 and row 6 on the grid
    Vector2 position;
    Texture2D texture;

    Food()
    {
        Image image = LoadImage("food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = GenerateRandomPos(); 
    
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    // The function that draws the food on the screen
    void Draw()
    {
        /* DrawRectangle(x_pos, y_pos, width, height, color)
           We multiply the grid position (like 5) by the cellSize (30) 
           to find the exact pixel location on the screen. */
        //DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
        DrawTexture(texture, position.x * cellSize,  position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPos()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x,y};
    }
};

int main () {

    // Print a message to the console (the black terminal window)
    cout << "Starting the game..." << endl;

    // Create the game window (Width: 750 pixels, Height: 750 pixels)
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");

    // Tell the game to run at 60 frames per second (smoothness)
    SetTargetFPS(60);

    // Create a 'food' object using our Food class blueprint
    Food food = Food();

    Snake snake = Snake();

    // The Main Game Loop: Runs repeatedly until the window is closed
    while(WindowShouldClose() == false)
    {
        // Setup for drawing on the screen
        BeginDrawing();

        snake.Update();

        // 1. Fill the entire background with our light green color
        ClearBackground(green);

        // 2. Call the Draw function from our food object to paint the food square
        food.Draw();

        snake.Draw();

        // Finish drawing and display everything to the user
        EndDrawing();
    }

    // Close the window and clean up memory before the program ends
    CloseWindow();
    return 0;
   
}
