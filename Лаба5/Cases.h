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
using namespace std;
#pragma once
struct PswKeyText {
    string password;
    string key;
    vector<string> text;
};
vector <string> Encryption(vector <string>& contwithstr, string key, int numbofcyph);
void EncryptCase(int keyoption, int numbofcyph, string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr);
void EncryptCases(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr);
vector <string> Decryption(vector <string>& contwithstr, string key, int numbofcyph);
void DecryptCase(PswKeyText& pswkeytext, string& psw, string& psw_confirm, string& path, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr, int numbofcyph);
void DecryptCases(PswKeyText& pswkeytext, string& psw, string& psw_confirm, string& path, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr);
void MainMenuCases(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr, PswKeyText pswkeytext);
