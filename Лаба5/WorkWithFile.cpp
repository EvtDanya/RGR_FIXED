#include "WorkWithFile.h"
#include "Allmenu.h"
vector<string> OpenNReadFile(vector <string> contwithstr, const string& fileName, bool& go_out) {//open file and read strings we need to encrypt
    string str;
    ifstream input;
    input.open(fileName);
    while (getline(input, str)) {
        //str = str + "\n";
        contwithstr.push_back(str);
    }
    if (!input.eof()) { //if the file could not be opened
        OutputError(5);
        go_out = true;
    }
    input.close();
    return contwithstr;
}
vector<string> GetPswKeyTextFromCont(vector<string> contwithstr,string& psw, string& key, bool& go_out, bool needkey) {
    string str;
    //разделить строку по пробелам и записать в соотв ячейки
    stringstream strstream(contwithstr[0]);
    vector<string> buffer;
    int count = 0;
    while (getline(strstream, str, ' '))
    {
        count++;
        buffer.push_back(str);
    }
    if ((needkey && count != 2) || (!needkey && count != 1)) {
        OutputError(9);
        go_out = true;
    }
    else {
        psw = buffer[0];
        if (needkey) {
            key = buffer[1];
        }
        contwithstr.erase(contwithstr.begin());
        //записать остальное в вектор
    }
    return contwithstr;
}
void Ofstream(vector <string> contwithstr, const char* fileName, string password, bool needkey, string key, bool& go_out, bool decrypted) {//function for writing to a file
    ofstream output; //stream to write
    output.open(fileName); //opening the file for recording
    if (output.is_open())
    {
        if (decrypted) {
            for (auto i = 0; i < contwithstr.size(); i++) {//writing encrypted strings to a file
                output << contwithstr.at(i) << endl;
            }
        }
        else {
            if (needkey) {
                output << password << ' ' << key << endl; //writing a password to a file
            }
            else {
                output << password << endl; //writing a password to a file
            }
            for (auto i = 0; i < contwithstr.size(); i++) {//writing encrypted strings to a file
                output << contwithstr.at(i) << endl;
            }
        }
    }
    else { //if it was not possible to write to a file
        OutputError(7);
        go_out = true;
    }
    output.close();
}
void AutoOpen(const char* pathtotxt) {//open with notepad.exe
    system(pathtotxt);
}