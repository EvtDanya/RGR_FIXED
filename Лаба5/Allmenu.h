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
int PositionInMenu(int count_of_menus, int option, bool& esc);
void MainMenu(int header, int pos);
void ChooseCypherMenu(int header, int pos);
void EntryPswMenu1(int header);
void EntryPswMenu2();
void EntryPswMenuForDecr(int header, int count);
void EntryPathMenu();
void KeyMenu(int header, int option);
