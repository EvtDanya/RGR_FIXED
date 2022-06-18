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
void Separate();
void OutputTextForHeader(int header);
void OutputError(int numboferror);
void Header(int header);
void Picture();
void MainMenu(int header);
void ChooseCypherMenu(int header);
void EntryPswMenu1(int header);
void EntryPswMenu2();
void EntryPswMenuForDecr(int header, int count);
void EntryPathMenu();
void KeyMenu(int header, int option);
