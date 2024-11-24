# Snake Game 🐍

A simple console-based Snake game implemented in C++. This project demonstrates basic game mechanics, rendering, and player interaction in a terminal environment.

## Features ✨
- **Dynamic gameplay**:
  - Snake moves around the board and grows longer when it eats fruit.
  - Wrap-around boundaries allow the snake to reappear on the opposite side.
- **Speed control**:
  - Use `+` to increase speed and `-` to decrease it during gameplay.
- **Pause and Resume**:
  - Pause the game by pressing `P`.
- **Game Over Screen**:
  - Displays your final score when the game ends.
- **Customizable Settings**:
  - Easily modify the game board dimensions and initial speed.

## How to Play 🎮
1. **Run the program**:
   - Compile and execute the `snake_game.cpp` file.
2. **Controls**:
   - `W`: Move Up
   - `S`: Move Down
   - `A`: Move Left
   - `D`: Move Right
   - `+`: Increase snake speed
   - `-`: Decrease snake speed
   - `P`: Pause the game
   - `X`: Exit the game
3. **Objective**:
   - Eat as many fruits (`F`) as possible without colliding with the snake's own tail.
   - Each fruit increases your score by 10 and makes the snake longer.


Code Highlights 🧩

Game Mechanics:
Snake movement is controlled using an array to track the positions of the head and tail.
Dynamic fruit placement ensures fruits don't spawn on the snake.

Speed Control:
Adjustable snake speed using a speed variable.
Boundary checks ensure speed remains within playable limits.

Clean Console Output:
Utilizes Windows-specific APIs like SetConsoleCursorPosition for smooth rendering.
Future Improvements 🌟
Add levels or increasing difficulty as the game progresses.
Include a scoreboard or high-score feature.
Portability: Modify for compatibility with Unix-based systems.
Add colorful output for better visuals.

License 📜
This project is licensed under the MIT License.
