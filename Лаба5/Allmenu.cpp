#include "Allmenu.h"
void Separate() {
    cout << "+------------------------------------------------------------+\n";
}
void OutputTextForHeader(int header) { //Stroka menu s viborom teksta
    switch (header)
    {
    case (1): { //main menu
        cout << '|' << setw(26) << ' ' << "Main menu" << setw(27) << "|\n";
        break;
    }
    case (2): { //cipher selection menu
        cout << '|' << setw(20) << ' ' << "Cipher selection menu" << setw(21) << "|\n";
        break;
    }
    case (3): {//menu for password
        cout << '|' << setw(21) << ' ' << "Password entry menu" << setw(22) << "|\n";
        break;
    }
    case (4): {//menu for path entering
        cout << '|' << setw(20) << ' ' << "File path entry menu" << setw(22) << "|\n";
        break;
    }
    case (5): {//key entering
        cout << '|' << setw(23) << ' ' << "Key entry menu" << setw(25) << "|\n";
        break;
    }
    default:
        break;
    };
}
void OutputError(int numboferror) {
    switch (numboferror)
    {
    case (1): { //wrong key is pressed
        cout << "Incorrect input!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (2): { //the password was not entered
        cout << "Error! The password must be entered!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (3): {//different passwords entered
        cout << "Error! Passwords are different!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (4): {//the path was not entered
        cout << "Error! The path must be entered!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (5): {//Error opening file
        cout << "Error opening file!\nYou may have specified the path to a non-existent file\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (6): {//if pressend space
        cout << " You cannot use such symbol! Press any key to continue";
        _getch();
        for (int i = 0; i < 54; i++) {
            cout << (char)8 << ' ' << (char)8;
        }
        break;
    }
    case (7): {//if it didn't work out, write to a file
        cout << "Error in working with the file!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (8): {//the key was not entered 
        cout << "Error! The key must be entered!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (9): {
        cout << "An error occurred while reading the file!\n";
        cout << "The file may be corrupted\n";
        cout << "Check the integrity of the password, key and text\n";
        cout << "Press any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (10): {//different passwords entered
        cout << "Error! Passwords are different!\nPress any key to try again";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (11): {
        cout << "Error! The password must be entered!\nPress any key to try again";
        _getch();//waiting for a key to be pressed
        break;
    }
    default:
        break;
    };
}
void Header(int header) {//shapka
    Separate();
    OutputTextForHeader(header);
    Separate();
}
void Picture() { //output picture 
    string str;
    ifstream input;
    input.open("doh.txt");
    system("cls");//clear the screen
    cout << setw(10) << ' ' << "Thanks for using our program!\n";
    while (getline(input, str)) {
        cout << str << endl;
    }
    if (!input.eof()) { //if the file could not be opened
        exit(0);
    }
    input.close();
    Sleep(2000);//wait for 2 seconds
    system("cls");//clear the screen
}
void MainMenu(int header) { //For printing the main menu
    system("cls");//clear the screen
    Header(header);
    cout << "All characters except English letters and numbers are ignored!\n";
    cout << "Press \"1\": \x1b[31mencryption\x1b[0m\n"; //output red text with construction \x1b[31m...\x1b[0m
    cout << "Press \"2\": \x1b[31mdecryption\x1b[0m\n"; //output red text
    cout << "The decryption file is obtained by encrypting the message thro-\nugh the program, due to the password is hashed and the key is \nencrypted. ";
    cout << "English letters and numbers are encrypted (not in \nall ciphers). ";
    cout << "The message can contain several lines.\n";
    cout << "Press \"Esc\": \x1b[31mexit the programm\x1b[0m\n"; //output red text
    Separate();
}
void ChooseCypherMenu(int header) {//for printing the menu with choosing cyphers
    system("cls"); //clear the screen
    Header(header);
    cout << "1 - Gronsfeld cipher" << setw(36) << "4 - The Vigener Cipher*\n";
    cout << "2 - Tarabarskaya gramota" << setw(30) << "5 - The Vernam cipher\n";
    cout << "3 - The Atbash cipher" << setw(28) << "6 - Morse Code**\n";
    cout << "* lowercase letters become uppercase letters(for key too)\n";
    cout << "** some symbols are not readable, they are deleted, uppercase\n";
    cout << "letters become lowercase\n";
    cout << "Press the cypher number or press \"Esc\" to return\n";
    Separate();
}
void EntryPswMenu1(int header) { //Menu for first enter of password
    system("cls"); //clear screen
    Header(header);
    cout << "The password will be saved in the encrypted file\n";
    cout << "Enter the password and press \"Enter\"\n";
    cout << "You \x1b[31mcan only use\x1b[0m numbers and letters of the English alphabet\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
void EntryPswMenu2() {//Menu for second enter of password to confirm first
    Separate();
    cout << "Confirm your password >> \n";
    Separate();
}
void EntryPswMenuForDecr(int header, int count) { //Menu for enter of password for decryption
    system("cls"); //clear screen
    Header(header);
    cout << "Please enter your password and press \"Enter\"\n";
    cout << "You \x1b[31mcan only use\x1b[0m numbers and letters of the English alphabet\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    cout << "You have " << count << " attempts left!\n";
    Separate();
}
void EntryPathMenu() { //menu for path entering
    system("cls"); //clear screen
    Header(4);
    cout << "The file must have the .txt extension\n";
    cout << "If the file is located in the same folder with the project\n";
    cout << "You need only to enter the file name (including .txt)\n";
    cout << "Specify the path to the file (or just the file name) and press \"Enter\"\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
void KeyMenu(int header, int option) {//For printing the main menu
    system("cls");//clear the screen
    Header(header);
    cout << "Please enter key for cypher and press \"Enter\"\n"; //output red text with construction \x1b[31m...\x1b[0m
    if (option == 1) { cout << "You \x1b[31mcan only use\x1b[0m numbers and letters of the English alphabet\n"; }
    else if (option == 2) { cout << "You \x1b[31mcan only use\x1b[0m numbers\n"; }
    else { cout << "You \x1b[31mcan only use\x1b[0m letters of the English alphabet\n"; }
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}