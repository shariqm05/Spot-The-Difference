/*
Title: proj1.cpp
Author: Shariq Moghees
Date: 9-26-24
Section: 22
E-mail: shariqm1@umbc.edu

Desc: A program that runs a "Spot the Difference" game using ASCII art.
The user loads a file using commands from the menu, and then can play the game.
Two images are displayed. the first is the original and the second having one character altered.
The player must guess the correct row and column of the changed character to win.
*/

//libraries imported
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

//Global Constants: Rows and Columns of the ASCII Art 
const int ROWS = 10;
const int COLS = 21;

void loadFile(char charArr[ROWS][COLS]) {
/*
-Asks the user to input the name of the file they want to load
-If the file is not found, a message is printed saying so
-If the file is found, a "Done" message will print
-Stores every character in the file in the cahracter array
*/
    string fileName;
    cout << "Enter the name of the file(.txt) to load: " << endl;
    cin >> fileName;
    ifstream fileArt(fileName);

    int fRow;
    int fCol;
    char fChar;

    //opening and processing file into the character array
    if (fileArt.is_open()){
        while(fileArt >> fRow >> fCol >> fChar){
            charArr[fRow][fCol] = fChar;
        }
    }
    else{
        cout << "File does not exist." << endl;
    }
}

void displayArt(char charArr[ROWS][COLS]){
/*
-takes the character array as a parameter.
-Uses a for loop to print each character in the array separately
-The printed array displays the original picture with coordinate labels
*/
    //column coordinates
    cout << "  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl;
    for (int r = 0; r < ROWS; r++) {
        cout << r; //row coordinates
        for (int c = 0; c < COLS; c++) {
            cout << " " << charArr[r][c];  // Print each character in the row
        }
        cout << endl;  // Move to the next line after printing the row
    }

}

void clearArray(char charArr[ROWS][COLS]){
/*
-sets every element within the character array as a space
-Clears the character array so that a new file can be loaded in
*/
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            charArr[r][c] = ' ';
        }
    }
}

bool guessChange(char copyArr[ROWS][COLS]){
/*
-takes the duplicated array with a difference as the parameter
-Asks user to guess the row the changed character is in
-Then asks for the column
-prints message that says if they guessed correctly or not.

-Return T/F for whether the user guessed the correct coordinate
*/
}

void playGame(char charArr[ROWS][COLS]){
/*
-Handles general game flow by calling other functions
-Checks to see if a file is loaded
-Makes a duplicate of the orginial char array with a difference in one char
-Displays both pictures(diplayArt)
-Calls guessChange until the player guesses correctly
-goes back to menu
*/
}

int main(){

    char charArr[ROWS][COLS]; //empty character array for ASCII art
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
        charArr[r][c] = ' ';
        }
    }

    bool isRunning = true;

    while(isRunning){
        //main menu logic
        int command;
        cout << "What would you like to do?" << endl;
        cout << "1. Load ASCII Art from File" << endl;
        cout << "2. Display Art" << endl;
        cout << "3. Play Game" << endl;
        cout << "4. Exit" << endl;
        cin >> command; //command input
        
        //input validation for command input
        while (command < 1 || command > 4){
            cout << "What would you like to do?" << endl;
            cout << "1. Load ASCII Art from File" << endl;
            cout << "2. Display Art" << endl;
            cout << "3. Play Game" << endl;
            cout << "4. Exit" << endl;
            cin >> command;
        }

        //SWITCH STATEMENT FOR HANDLING COMMAND INPUT HERE
    }

    return 0;
}

