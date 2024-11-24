#include <iostream>
#include <conio.h>
#include <windows.h> // For Sleep function
using namespace std;

// Game variables
bool gameOver;
const int width = 20;  // Width of the game area
const int height = 20; // Height of the game area
int x, y, fruitX, fruitY, scoreboard; // Snake head and fruit positions, score
int tailX[100], tailY[100];           // Arrays for the snake's tail positions
int nTail;                           // Current length of the snake's tail
int speed = 100;                     // Initial speed in milliseconds
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir; // Current direction of the snake

// Initialize the game
void Setup()
{
    gameOver = false;
    dir = STOP; // Snake starts stationary
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width; // Random fruit position
    fruitY = rand() % height;
    scoreboard = 0;          // Reset score
    nTail = 0;               // Reset tail length
}

// Draw the game area
void Draw()
{
    // Reset cursor position for smooth rendering
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    // Hide console cursor for better visual experience
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    // Draw the top border
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    // Draw the game area with snake and fruit
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (j == 0 || j == width + 1) // Left and right borders
                cout << "|";
            else if (i == y && j == x + 1) // Snake's head (adjusted for border offset)
                cout << "O";
            else if (i == fruitY && j == fruitX + 1) // Fruit position
                cout << "F";
            else
            {
                // Check if the current position matches any part of the tail
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j - 1 && tailY[k] == i) // Adjusted for border offset
                    {
                        cout << "o"; // Tail segment
                        print = true;
                        break;
                    }
                }
                if (!print)
                    cout << " "; // Empty space
            }
        }
        cout << endl;
    }

    // Draw the bottom border
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    // Display the score and current speed
    cout << "Score: " << scoreboard << "  |  Speed: " << speed << "ms" << endl;
}

// Handle player input
void Input()
{
    if (_kbhit()) // Check if a key was pressed
    {
        switch (_getch())
        {
        case 'a': // Move left
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd': // Move right
            if (dir != LEFT) dir = RIGHT;
            break;
        case 's': // Move down
            if (dir != UP) dir = DOWN;
            break;
        case 'w': // Move up
            if (dir != DOWN) dir = UP;
            break;
        case '+': // Increase speed
            if (speed > 10) speed -= 10; // Minimum speed is 10ms
            break;
        case '-': // Decrease speed
            if (speed < 500) speed += 10; // Maximum speed is 500ms
            break;
        case 'x': // Exit the game
            gameOver = true;
            break;
        case 'p': // Pause the game
            cout << "Game Paused. Press any key to continue...";
            _getch(); // Wait for a key press to resume
            break;
        }
    }
}

// Game logic for movement and collision detection
void Logic()
{
    // Update tail positions
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Update snake's head position based on the direction
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    case UP:
        y--;
        break;
    default:
        break;
    }

    // Boundary wrapping
    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;
    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    // Check if the snake collides with its tail
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    // Check if the snake eats the fruit
    if (x == fruitX && y == fruitY)
    {
        scoreboard += 10;       // Increase score
        fruitX = rand() % width; // Place new fruit
        fruitY = rand() % height;
        nTail++;                // Increase tail length
    }
}

// Main function
int main()
{
    Setup(); // Initialize the game

    while (!gameOver) // Main game loop
    {
        Draw();   // Render the game
        Input();  // Handle player input
        Logic();  // Update game state
        Sleep(speed); // Control the game speed
    }

    // Game Over screen
    system("cls"); // Clear the screen
    cout << "Game Over! Your Score: " << scoreboard << endl;
    cout << "Press any key to exit..." << endl;

    _getch(); // Wait for user input before exiting
    return 0;
}
