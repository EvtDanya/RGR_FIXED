#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include<map>
using namespace std;
#pragma once

vector<string> OpenNReadFile(vector <string> contwithstr, const string& fileName, bool& go_out);
vector<string> GetPswKeyTextFromCont(vector<string> contwithstr, string& psw, string& key, bool& go_out, bool needkey);
void Ofstream(vector <string> contwithstr, const char* fileName, string password, bool needkey, string key, bool& go_out, bool decrypted);
void AutoOpen(const char* pathtotxt);