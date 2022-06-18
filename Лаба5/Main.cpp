#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include "Allmenu.h"
#include "sha256.h" 
#include "Ciphers.h"
#include "PasswordKeyPath.h"
#include "WorkWithFile.h"
#include "Cases.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");
    PswKeyText pswkeytext;
    vector <string> contwithstr;
    bool go_out, esc, needkey;//go_out - for errors and break cycles, esc - if pressed escape
    string psw, psw_confirm, path, key; //password and confirmation of password, path to file, history of entering paths
    MainMenuCases(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, pswkeytext);
}