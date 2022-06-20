#include "Allmenu.h"
#include "sha256.h" 
#include "Ciphers.h"
#include "PasswordKeyPath.h"
#include "WorkWithFile.h"
#include "Cases.h"
vector <string> Encryption(vector <string>& contwithstr, string key, int numbofcyph) {//encryption with the selected cypher
    for (auto i = 0; i < contwithstr.size(); i++) {
        switch (numbofcyph)//depending on the chosen cipher
        {
        case (1): {
            contwithstr.at(i) = Encrypt1(contwithstr.at(i), key);
            break;
        }
        case (2): {
            contwithstr.at(i) = Encrypt2(contwithstr.at(i));
            break;
        }
        case (3): {
            contwithstr.at(i) = Encrypt3(contwithstr.at(i));
            break;
        }
        case (4): {
            key = LowToUpForKey(key);
            contwithstr.at(i) = Encrypt4(contwithstr.at(i), key);
            break;
        }
        case (5): {
            contwithstr.at(i) = Encrypt5(contwithstr.at(i), key);
            break;
        }
        case (6): {
            contwithstr.at(i) = Encrypt6(contwithstr.at(i));
            break;
        }
        default:
            break;
        }
    }
    return contwithstr;
}
void EncryptCase(int keyoption, int numbofcyph, string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr) {
    bool key_received = true;
    if (needkey) {
        key = Key(keyoption, key, go_out, esc);
        if (key.empty()) {
            key_received = false;
            OutputError(8);
        }
    }
    if (!go_out && key_received) {
        psw = Psw(psw, psw_confirm, go_out, esc);
        if ((psw.empty() || psw_confirm.empty()) && (!go_out)) //if one of the passwords is not entered
        {
            OutputError(2);
        }
        else if ((CheckPsw(psw, psw_confirm) == false) && (!go_out)) { //different passwords entered
            OutputError(3);
        }
        else if (!go_out) {//if successfully
            string hashpsw = SHA256::hashString(psw);
            path = Path(path, go_out, esc);
            if (!go_out) {//if successfully
                contwithstr = OpenNReadFile(contwithstr, path, go_out);
                if (!go_out) {//if successfully
                    Encryption(contwithstr, key, numbofcyph);
                    key = EncryptForKey(key);
                    string newpath = NewPath(1, path);//get new name and path to this new file from old one
                    const char* b = newpath.c_str(); //its for using autoopen function(system("") dont work with strings)
                    Ofstream(contwithstr, b, hashpsw, needkey, key, go_out, false);//false, because we are recording encrypted text
                    if (!go_out) {//if successfully
                        AutoOpen(b);//open this file with notepad
                        contwithstr.clear();//clear container if we want to work with program again
                    }
                }
            }
        }
    }
}
void EncryptCases(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr) {
    int keyoption = 2, nymbofcyph = 1;
    ChooseCypherMenu(2);
    char choise_cypher = _getch();//waiting for a key to be pressed
    switch (choise_cypher) {//depending on the key pressed
    case '1': {
        needkey = true;//the cypher need a key
        keyoption = 2;//we can enter only numbers for this key
        nymbofcyph = 1;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '2': {
        needkey = false;//the cypher does not need a key    
        nymbofcyph = 2;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '3': {
        needkey = false;//the cypher does not need a key
        nymbofcyph = 3;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '4': {
        needkey = true;//the cypher does not need a key
        keyoption = 3;//we can enter only letters for this key
        nymbofcyph = 4;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '5': {
        needkey = true;//the cypher does not need a key
        keyoption = 3;//we can enter only letters for this key
        nymbofcyph = 5;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '6': {
        needkey = false;//the cypher does not need a key
        nymbofcyph = 6;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case 27: { break; } //if pressed esc
    default: {//if the wrong key is pressed
        OutputError(1);
        break;
    }
    };
}
vector <string> Decryption(vector <string>& contwithstr, string key, int numbofcyph) {//encryption with the selected cypher
    for (auto i = 0; i < contwithstr.size(); i++) {
        switch (numbofcyph)//depending on the chosen cipher
        {
        case (1): {
            contwithstr.at(i) = Decrypt1(contwithstr.at(i), key);
            break;
        }
        case (2): {

            contwithstr.at(i) = Decrypt2(contwithstr.at(i));
            break;
        }
        case (3): {
            contwithstr.at(i) = Decrypt3(contwithstr.at(i));
            break;
        }
        case (4): {
            key = LowToUpForKey(key);
            contwithstr.at(i) = Decrypt4(contwithstr.at(i), key);
            break;
        }
        case (5): {
            contwithstr.at(i) = Decrypt5(contwithstr.at(i), key);
            break;
        }
        case (6): {
            contwithstr.at(i) = Decrypt6(contwithstr.at(i));
            break;
        }
        default:
            break;
        }
    }
    return contwithstr;
}
void DecryptCase(PswKeyText& pswkeytext, string& psw, string& psw_confirm, string& path, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr, int numbofcyph) {
    path = Path(path, go_out, esc);
    if (!go_out) {//if successfully
        contwithstr = OpenNReadFile(contwithstr, path, go_out);
        if (!go_out) {//if successfully
            pswkeytext.text = GetPswKeyTextFromCont(contwithstr, pswkeytext.password, pswkeytext.key, go_out, needkey);
            if (!go_out) {//if successfully
                string hashpsw;
                auto attempts = 5;
                while (attempts > 0) {
                    psw = PswForDecr(psw, attempts, go_out, esc);
                    if (!psw.empty() && (!esc)) //if the string with password is not empty- continue
                    {
                        //хэшируем
                        hashpsw = SHA256::hashString(psw);
                        if (CheckPsw(hashpsw, pswkeytext.password)) {
                            break;
                        }
                        else {
                            OutputError(10);
                        }
                    }
                    else if (esc) { //if pressed escape- flag for returning
                        go_out = true;
                        break;
                    }
                    else if (psw.empty()) {
                        OutputError(11);
                        continue;
                    }
                    attempts--;
                }
                if (!go_out && CheckPsw(hashpsw, pswkeytext.password)) {//if successfully
                    pswkeytext.key = DecryptForKey(pswkeytext.key);
                    Decryption(pswkeytext.text, pswkeytext.key, numbofcyph);
                    string newpath = NewPath(2, path);//get new name and path to this new file from old one
                    const char* b = newpath.c_str(); //its for using autoopen function(system("") dont work with strings)
                    Ofstream(pswkeytext.text, b, psw, needkey, pswkeytext.key, go_out, true); //true, because we are recording decrypted text
                    if (!go_out) {//if successfully
                        AutoOpen(b);//open this file with notepad
                        //clear all because we will work again with text
                        pswkeytext.password.clear();
                        pswkeytext.key.clear();
                        pswkeytext.text.clear();
                        contwithstr.clear();//clear container if we want to work with program again
                    }
                }
            }
        }
    }
}
void DecryptCases(PswKeyText& pswkeytext, string& psw, string& psw_confirm, string& path, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr) {
    int keyoption = 2, nymbofcyph = 1;
    ChooseCypherMenu(2);
    char choise_cypher = _getch();//waiting for a key to be pressed
    switch (choise_cypher) {//depending on the key pressed
    case '1': {
        needkey = true;//the cypher need a key
        nymbofcyph = 1;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '2': {
        needkey = false;//the cypher need a key
        nymbofcyph = 2;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '3': {
        needkey = false;//the cypher need a key
        nymbofcyph = 3;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '4': {
        needkey = true;//the cypher need a key
        nymbofcyph = 4;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '5': {
        needkey = true;//the cypher need a key
        nymbofcyph = 5;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '6': {
        needkey = false;//the cypher need a key
        nymbofcyph = 6;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case 27: {break; }//if pressed esc
    default: { //if the wrong key is pressed
        OutputError(1);
        break;
    }
    };
}
void MainMenuCases(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr, PswKeyText pswkeytext) {
    while (1) { //for returning to the main menu
        go_out = false;//if the flags have already been activated, then reset
        esc = false;
        MainMenu(1);
        char choise_from_main_menu = _getch();//waiting for a key to be pressed
        switch (choise_from_main_menu) //depending on the key pressed
        {
        case '1': {
            EncryptCases(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
            break;
        }
        case '2': {
            DecryptCases(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr);
            break;
        }
        case 27: {//if pressed esc
            Picture();
            exit(0);//program shutdown
        }
        default: {//if the wrong key is pressed
            OutputError(1);
            break;
        }
        };
    }
}