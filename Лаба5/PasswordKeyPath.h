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
bool CanUse(int option, char ch);
string GetPsw(bool& esc);
string Psw(string psw1, string& psw2, bool& go_out, bool& esc);
string PswForDecr(string psw1, int count, bool& go_out, bool& esc);
bool CheckPsw(string psw1, string psw2);
string GetPath(bool& esc);
string Path(string path, bool& go_out, bool& esc);
string GetKey(bool& esc, int option);
string Key(int option, string key, bool& go_out, bool& esc);
string NewPath(int option, string path);