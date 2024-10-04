# Spot the Difference

This is a text-based game where users can load a file containing ASCII art and then spot the subtle one-character difference between two images. The game was developed using **C++** in **Visual Studio**, and it is my first C++ project after gaining experience with Python and Java. The game enhances the user's attention to detail while offering a fun, interactive challenge.

## Project Overview

In **Spot the Difference**, players load an ASCII art image from a text file. The program displays two images side by side: the original and a modified version with one altered character. Players must identify the location of the changed character by guessing its row and column coordinates. The game continues until the player correctly identifies the difference.

### Features

- **File Input**: Players load their own ASCII art files, making the game highly customizable. I’ve also provided three sample text files in the repository for you to try out:
  - A small test file.
  - Two full-fledged ASCII art files to play the game for real.
- **Grid Coordinates**: The ASCII art is displayed on a grid with labeled row and column numbers to help players locate the differences.
- **Player Interaction**: Players input their guesses for the row and column of the altered character until they find the correct location.
- **Random Alteration**: The program randomly changes a single character in the second image for each new game.

### How to Play

1. **Load a File**: Use the menu to load an ASCII art file from your local system. You can either use the provided sample files or load your own ASCII art file as long as it doesn’t exceed the maximum **10 rows** and **21 columns**, which are defined as constants in the source code.
2. **Spot the Difference**: Two images will be displayed—one original and one with a subtle change. Guess the correct row and column where the change is located.
3. **Win the Game**: Keep guessing until you identify the changed character correctly.

### Commands Overview

- `1. Load ASCII Art from File`: Allows you to select and load a file containing ASCII art.
- `2. Display Art`: Displays the loaded ASCII art image on a grid.
- `3. Play Game`: Starts the "Spot the Difference" game after the file is loaded.
- `4. Exit`: Exits the game.

### What I Learned

- **C++ Fundamentals**: As this is my first project in C++, I learned about core concepts such as pointers, arrays, file handling, and C++-specific syntax, which differs from my previous experience in Python and Java.
  
- **File Handling in C++**: I explored how to read files and process input data in C++, which helped me improve my understanding of I/O operations in this language.

- **Grid-Based Display**: I learned how to format and display data in a grid layout using loops and how to implement user-friendly input and output handling.

- **Memory Management**: Unlike Python or Java, working with arrays and data management in C++ made me more conscious of memory allocation and data processing efficiency.

## Requirements

- **C++ Compiler** (e.g., Visual Studio, g++)
- **ASCII Art Files**: The game accepts files containing ASCII characters to be used as input, as long as they do not exceed the maximum **10 rows** and **21 columns**.

## How to Run

1. Clone this repository to your local machine.
2. Compile the code using a C++ compiler:
   ```bash
   g++ SpotTheDifference.cpp -o SpotTheDifference
   ```
3. Run the program:
   ```bash
   ./SpotTheDifference
   ```
4. Follow the prompts and enjoy the game!

### Future Improvements

In future iterations of this game, I plan to enhance the gameplay experience by adding the following features:

1. **Customizable Difficulty**: Allow players to choose different grid sizes for more challenging experiences.
2. **Timed Mode**: Introduce a timed game mode where players must find the difference within a limited amount of time.
3. **Scorekeeping**: Implement a scoring system to track how quickly and accurately players can find the difference.

These updates will enrich the game by providing more variety and replayability.

### Contacts

- LinkedIn: [Shariq Moghees](https://www.linkedin.com/in/shariq-moghees-02ba712b2/)
- Email: shariqm2005@gmail.com
