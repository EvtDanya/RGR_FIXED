#include "PasswordKeyPath.h"
#include "Allmenu.h"
bool CanUse(int option, char ch) {
    if (option == 1) {//letters n numbers
        string canUse = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        if (canUse.find(char(ch)) != string::npos) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (option == 2) {//numbers
        if (isdigit(ch)) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (option == 3) { //letters
        string canUse = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (canUse.find(char(ch)) != string::npos) {
            return true;
        }
        else {
            return false;
        }
    }
}
string GetPsw(bool& esc) { //password entry function
    string passw;
    int ch = 0; //symbol variable for entering
    while (true)
    {
        ch = _getch(); //put the code of the pressed key in the ch
        if (ch == 13) // Enter - interrupt
        {
            cout << '\n';
            break;
        }
        else if (ch == 27) //Esc return to the main menu
        {
            esc = true;
            break;
        }
        else if (ch == 8) //Backspace - delete symbols
        {
            cout << (char)8 << ' ' << (char)8;
            //offset one symbol to the left, output whitespace instead of a symbol
            //offset one symbol to the left once again 
            //this means that we have deleted the entered symbol
            if (!passw.empty()) //if our string is not empty
                passw.pop_back(); //delete the last symbol from the string

        } //1 - because we can only use numbers and english letters
        else if (!CanUse(1, char(ch))) {//if we cant use this symbol(not number or not english letter)
            OutputError(6);
        }
        else //if pressed symbol for password
        {
            cout << '*';  //output * instead of a symbol 
            passw += (char)ch;  //Turning a code from an integer(ascii-code) into a symbol 
        }
    }
    return passw;
}
string Psw(string psw1, string& psw2, bool& go_out, bool& esc) { //Menu with password entering
    EntryPswMenu1(3);
    psw1 = GetPsw(esc); //we get the password through the function
    if (!psw1.empty() && (!esc)) //if the string with password is not empty- continue
    {
        EntryPswMenu2();
        psw2 = GetPsw(esc); //we get the password through the function
        Separate();
    }
    if (esc) { go_out = true; } //if pressed escape- flag for returning
    return psw1;
}
string PswForDecr(string psw1, int count, bool& go_out, bool& esc) { //Menu with password entering
    EntryPswMenuForDecr(3, count);
    psw1 = GetPsw(esc); //we get the password through the function    
    return psw1;
}
bool CheckPsw(string psw1, string psw2) { //the function checks whether the passwords entered are the same
    if (psw1 == psw2) { return true; }
    else { return false; }
}
string GetPath(bool& esc) { //path to file entry function
    string path;
    int ch = 0; //symbol variable for entering
    while (true)
    {
        ch = _getch(); //put the code of the pressed key in the ch
        if (ch == 13) // Enter - interrupt
        {
            cout << '\n';
            break;
        }
        else if (ch == 27) //Esc return to main menu
        {
            esc = true;
            break;
        }
        else if (ch == 8) //Backspace - delete symbols
        {
            cout << (char)8 << ' ' << (char)8;
            //offset one symbol to the left, output whitespace instead of a symbol
            //offset one symbol to the left once again 
            //this means that we have deleted the entered symbol
            if (!path.empty()) //if our string is not empty
                path.pop_back(); //delete the last symbol from the string
        }
        else
        {
            cout << (char)ch;       //output of the symbol that was entered
            path += (char)ch;       //Turning a code from an integer into a symbol
        }
    }
    return path;
}
string Path(string path, bool& go_out, bool& esc) { //function for getting path to file
    system("cls"); //clear screen
    Header(4);
    EntryPathMenu();//calling the menu function
    path = GetPath(esc);//we get the path through the function
    if (path.empty() && (!esc)) {//if the path is not entered, before that the go_out flag was not activated and escape wasnt pressed
        OutputError(4);
        go_out = true;
    }
    else if (esc) { go_out = true; }//if pressed escape
    return path;
}
string GetKey(bool& esc, int option) {//key entry function
    string key;
    int ch = 0; //symbol variable for entering
    while (true)
    {
        ch = _getch(); //put the code of the pressed key in the ch
        if (ch == 13) // Enter - interrupt
        {
            cout << '\n';
            break;
        }
        else if (ch == 27) //Esc return to the main menu
        {
            esc = true;
            break;
        }
        else if (ch == 8) //Backspace - delete symbols
        {
            cout << (char)8 << ' ' << (char)8;
            //offset one symbol to the left, output whitespace instead of a symbol
            //offset one symbol to the left once again 
            //this means that we have deleted the entered symbol
            if (!key.empty()) //if our string is not empty
                key.pop_back(); //delete the last symbol from the string

        }
        else if (!CanUse(option, char(ch))) {//
            OutputError(6);
        }
        else //if pressed symbol for password
        {
            cout << (char)ch;  //output * instead of a symbol 
            key += (char)ch;  //Turning a code from an integer(ascii-code) into a symbol 
        }
    }
    return key;
}
string Key(int option, string key, bool& go_out, bool& esc) {//Menu with key entering
    KeyMenu(5, option);
    key = GetKey(esc, option);
    if (esc) { go_out = true; }
    return key;
}
string NewPath(int option, string path) {//function for getting a new path to a new file
    for (auto i = 0; i < 4; i++) {//delete ".txt" from name
        path.pop_back();
    }
    if (option == 1) {  //new name for encrypted file
        path = path + "_encr.txt";
    }
    if (option == 2) { //new name for the decrypted file
        path = path + "_decr.txt";
    }
    return path;
}