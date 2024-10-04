/*
Title: SpotTheDifference.cpp
Author: Shariq Moghees
Date: 10-3-24

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
#include <cstdlib>
#include <ctime>

using namespace std;

//Global Constants: Rows and Columns of the ASCII Art 
const int ROWS = 10, COLS = 21;

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

    int fRow, fCol;
    char fChar;

    //opening and processing file into the character array
    if (fileArt.is_open()){
        while(fileArt >> fRow >> fCol >> fChar){
            charArr[fRow][fCol] = fChar;
        }
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
-The printed array displays the original picture with coordinate labels
*/
    //column coordinates
    cout << "   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20" << endl;
    for (int r = 0; r < ROWS; r++) {
        cout << r; //row coordinates
        for (int c = 0; c < COLS; c++) {
            cout << "  " << charArr[r][c];  // Print each character in the row
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

bool isFileLoaded(char charArr[ROWS][COLS]){
    //Checks if a file is loaded into the charArr by checking whether the file is fully empty or not
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            if (charArr[r][c] != ' '){
                return true;
            }
        }
    }
    return false;
}

bool isGuessRight(char origArr[ROWS][COLS], char copyArr[ROWS][COLS]){
/*
-takes the duplicated array with a difference as the parameter
-Asks user to guess the row the changed character is in
-Then asks for the column
-prints message that says if they guessed correctly or not.
-Return T/F for whether the user guessed the correct coordinate
*/
    int r, c; 
    cout << "What row is the change in?" << endl;
    cin >> r;
    cout << "What column is the change in?" << endl;
    cin >> c;

    //input validation
    while (r < 0 || r >= ROWS || c < 0 || c >= COLS){
        cout << "invalid input for row and/or column" << endl;
        cout << "What row is the change in?" << endl;
        cin >> r;
        cout << "What column is the change in?" << endl;
        cin >> c;
    }

    //checking the guessed character with the character from the orginal array
    //If the characters are different, then it was the changed character. 
    if(copyArr[r][c] != origArr[r][c]){
        return true;
    }
    return false;
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
    //declares and initializes the dupe array with the original
    char copyArr[ROWS][COLS]; 
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            copyArr[r][c] = charArr[r][c];
        }
    }

    //setting a radom coordinate to change
    int randRow = rand() % ROWS;
    int randCol = rand() % COLS;
    // setting a random character to fill that random coordinate between ASCI values of 33-126
    char randChar;
    do{
        randChar = rand() % 94 + 33;
    }while(randChar == charArr[randRow][randCol]);
    copyArr[randRow][randCol] = randChar;
    //display both original and dupe arrays. 
    displayArt(charArr);
    displayArt(copyArr);
    //user keeps guessing the location of the changed character until they get it right.
    while (!isGuessRight(charArr,copyArr)){
        cout << "That is incorrect!" << endl;
    }
    //win condition message
    cout << "You are correct!" << endl;
}

int main(){

    char charArr[ROWS][COLS]; //empty character array for ASCII art
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
        charArr[r][c] = ' ';
        }
    }

    bool isRunning = true;
    srand(time(0)); //primes the rand function

    while(isRunning){
        //main menu logic
        int command;
        cout << "What would you like to do?" << endl;
        cout << "1. Load ASCII Art from File" << endl;
        cout << "2. Display Art" << endl;
        cout << "3. Play Game" << endl;
        cout << "4. Exit" << endl;
        cin >> command; //command input
        
        //switch statement for handling input command logic.
        switch (command){
            case 1: //Load a file into the charArr
                clearArray(charArr); //ensure array is empty before loading a new file.
                loadFile(charArr);
                cout << "\n" << endl;
                break;
            case 2: //displays the loaded file on a coordinate grid
                if (isFileLoaded(charArr)){
                    displayArt(charArr);
                    cout << "\n" << endl;

                }
                else{
                    cout << "No file loaded.\n" << endl;
                }
                break;
            case 3: //begins the process the play the game of 'Spot-the-Difference'
                if (isFileLoaded(charArr)){
                    playGame(charArr);
                    clearArray(charArr); //clear the array after the game is over to load a new one in. 
                    cout << "\n" << endl;
                }
                else{
                    cout << "No file loaded.\n" << endl;
                }
                break; 
            case 4: //exit program
                cout << "Thank you for playing the Spot the Difference Game\n" << endl;
                isRunning = false;
                break;
                
            default: //input validation
                break;
        }
    }
    return 0;
}

