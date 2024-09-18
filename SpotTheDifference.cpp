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

    //opening and processing file into the character array
    if (fileArt.is_open()){
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                fileArt.get(charArr[r][c]);
            }
        }
        fileArt.close();
        cout << "Done" << endl;
    }    
    else{
        cout << "File does not exist." << endl;
    }
}

void displayArt(char charArr[ROWS][COLS]){
/*
-takes the character array as a parameter.
-Uses a for loop to print each character in the array separately
-The printed array displays the original picture
*/
}

void clearArray(char charArr[ROWS][COLS]){
/*
-sets every element within the character array as zero
-Clears the character array so that a new file can be loaded in
*/
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            charArr[r][c] = 0;
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

    char charArr[ROWS][COLS] = {{0}}; //empty character array for ASCII art
    bool isRunning = true; //looping boolean for program
    int command;

    while(isRunning){
        //main menu logic
        cout << "What would you like to do?" << endl;
        cout << "1. Load ASCII Art from File" << endl;
        cout << "2. Display Art" << endl;
        cout << "3. PLay Game" << endl;
        cout << "4. Exit" << endl;
        cin >> command; //command input
        //input validation for command input
        while (command < 1 || command > 4){
            cout << "What would you like to do?" << endl;
            cout << "1. Load ASCII Art from File" << endl;
            cout << "2. Display Art" << endl;
            cout << "3. PLay Game" << endl;
            cout << "4. Exit" << endl;
            cin >> command;
        }
        //SWITCH STATEMENT FOR HANDLING COMMAND INPUT HERE
    }

    return 0;
}

