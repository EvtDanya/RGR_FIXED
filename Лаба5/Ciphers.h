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
struct morse {
    string englow;
    string engup;
    string key;
};
string LowToUpForKey(string key);
string Encrypt4(string m, string k);
string Decrypt4(string m, string k);
vector<string> split(const string& inputstr, char delim);
string Encrypt6(string text);
string Decrypt6(string text);
string Encrypt5(string text, string key);
string Decrypt5(string text, string key);
string Encrypt1(string cEng, string keyEng);
string Decrypt1(string cEng, string keyEng);
string Encrypt2(string cEng);
string Decrypt2(string cEng);
string Encrypt3(string cEng);
string Decrypt3(string cEng);
string EncryptForKey(string cEng);
string DecryptForKey(string cEng);