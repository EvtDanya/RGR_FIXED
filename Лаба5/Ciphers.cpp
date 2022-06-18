#include "Ciphers.h"
string LowToUpForKey(string key) {
    for (auto& i : key) {
        if (i >= 97 && i <= 122) {
            i = ((int)i - 97) + 65;
        }
    }
    return key;
}
string Encrypt4(string m, string k) {
    string vig;
    char buffer;
    for (int ind = 0; ind < m.length(); ind++) {
        if (m[ind] >= 65 && m[ind] <= 90) {//for big letter
            vig += ((m[ind] + k[ind % k.length()]) % 26) + 65;//since we found the remainder of the division by the power of the alphabet
        } //add 65 to get the ciphertext letter itself
        else if (m[ind] >= 97 && m[ind] <= 122) {//if it's a small letter, make it big
            buffer = (m[ind] - 97) + 65;
            vig += (((int)buffer + k[ind % k.length()]) % 26) + 65;
        }
        else {
            vig += m[ind];
        }
    }
    return vig;
}
string Decrypt4(string m, string k) {
    string vig;
    for (int ind = 0; ind < m.length(); ind++) {
        if (m[ind] >= 65 && m[ind] <= 90) {
            vig += ((m[ind] - k[ind % k.length()]) + 26) % 26 + 65;
        }
        else {
            vig += m[ind];
        }
    }
    return vig;
}
vector<string> split(const string& inputstr, char delim)
{
    vector<string> buffer;
    stringstream strstream(inputstr);
    string str;
    while (getline(strstream, str, delim)) {
        buffer.push_back(str);
    }
    return buffer;
}
string Encrypt6(string text) {
    vector<morse> lang = {
    {"a","A", ".-"},
    {"b","B", "-..."},
    {"c","C", "-.-."},
    {"d","D", "-.."},
    {"e","E", "."},
    {"f","F", "..-."},
    {"g","G", "--."},
    {"h","H", "...."},
    {"i","I", ".."},
    {"j","J", ".---"},
    {"k","K", "-.-"},
    {"l","L", ".-.."},
    {"m","M", "--"},
    {"n","N", "-."},
    {"o","O", "---"},
    {"p","P", ".--."},
    {"q","Q", "--.-"},
    {"r","R", ".-."},
    {"s","S", "..."} ,
    {"t","T", "-"},
    {"u","U", "..-"},
    {"v","V", "...-"},
    {"w","W", ".--"},
    {"x","X", "-..-"},
    {"y","Y", "-.--"},
    {"z","Z", "--.."},
    {"0","0", "-----"},
    {"1","1", ".----"},
    {"2","2", "..---"},
    {"3","3", "...--"},
    {"4","4", "....-"},
    {"5","5", "....."},
    {"6","6", "-...."},
    {"7","7", "--..."},
    {"8","8", "---.."},
    {"9","9", "----."},
    {",",",",".-.-.-"},
    {".",".","......"},
    {"!","!","--..--"},
    {"?","?","..--.."},
    {"'","'",".----."},
    {"\"","\"",".-..-."},
    {";",";","-.-.-."},
    {":",":","---..."},
    {"-","-","-....-"},
    {"+","+",".-.-."},
    {"=","=","-...-"},
    {"_","_","..--.-"},
    {"/","/","-..-."},
    {"(","(","-.--."},
    {")",")","-.--.-"},
    {"&","&",".-..."},
    {"$","$","...-..-"},
    {"@","@",".--.-."},
    {" ", " ", " "}
    };
    string ch;
    string encr;
    vector <string> morse;
    morse = split(text, ' ');
    for (auto str : morse) {
        for (auto instr = 0; instr < str.length(); instr++) {
            ch = str[instr];
            for (auto j = 0; j < lang.size(); j++) {
                if (lang[j].englow == ch || lang[j].engup == ch) {
                    encr += lang[j].key + " ";
                }
            }
        }
        encr += " ";
    }
    return encr;//äîäåëàòü ÷òîáû â ñòðîêó ïðîáåëû äîáàâëÿëèñü è
}
string Decrypt6(string text) {
    vector<morse> lang = {
    {"a","A", ".-"},
    {"b","B", "-..."},
    {"c","C", "-.-."},
    {"d","D", "-.."},
    {"e","E", "."},
    {"f","F", "..-."},
    {"g","G", "--."},
    {"h","H", "...."},
    {"i","I", ".."},
    {"j","J", ".---"},
    {"k","K", "-.-"},
    {"l","L", ".-.."},
    {"m","M", "--"},
    {"n","N", "-."},
    {"o","O", "---"},
    {"p","P", ".--."},
    {"q","Q", "--.-"},
    {"r","R", ".-."},
    {"s","S", "..."} ,
    {"t","T", "-"},
    {"u","U", "..-"},
    {"v","V", "...-"},
    {"w","W", ".--"},
    {"x","X", "-..-"},
    {"y","Y", "-.--"},
    {"z","Z", "--.."},
    {"0","0", "-----"},
    {"1","1", ".----"},
    {"2","2", "..---"},
    {"3","3", "...--"},
    {"4","4", "....-"},
    {"5","5", "....."},
    {"6","6", "-...."},
    {"7","7", "--..."},
    {"8","8", "---.."},
    {"9","9", "----."},
    {",",",",".-.-.-"},
    {".",".","......"},
    {"!","!","--..--"},
    {"?","?","..--.."},
    {"'","'",".----."},
    {"\"","\"",".-..-."},
    {";",";","-.-.-."},
    {":",":","---..."},
    {"-","-","-....-"},
    {"+","+",".-.-."},
    {"=","=","-...-"},
    {"_","_","..--.-"},
    {"/","/","-..-."},
    {"(","(","-.--."},
    {")",")","-.--.-"},
    {"&","&",".-..."},
    {"$","$","...-..-"},
    {"@","@",".--.-."},
    {" ", " ", " "}
    };
    string decr;
    vector<string> morse;
    morse = split(text, ' ');
    for (auto i = 0; i < morse.size(); i++)
    {
        if (morse[i] == "")
        {
            decr += " ";
        }
        for (auto j = 0; j < lang.size(); j++)
        {
            if (lang[j].key == morse[i])
            {
                decr += lang[j].englow;
            }
        }
    }
    return decr;
}
string Encrypt5(string text, string key) {
    string encr;
    for (int ind = 0; ind < text.length(); ind++)
    {

        encr += text[ind] ^ key[ind % key.length()];
    }
    return encr;
}
string Decrypt5(string text, string key) {
    string decr;
    for (int ind = 0; ind < text.length(); ind++)
    {
        decr += text[ind] ^ key[ind % key.length()];

    }
    return decr;
}
string Encrypt1(string cEng, string keyEng) {
    string Crypted = cEng;  //crypted Crypted
    int i = 0, ii = 0; //Crypted position counter	
    while (Crypted[i] != '\0') { //value substitution		
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            Crypted[i] = 64 + abs((cEng[i] + (int)keyEng[ii] - 48 - 64)) % 26;
        }
        else if (cEng[i] >= 97 && cEng[i] <= 122) {
            Crypted[i] = 96 + abs((cEng[i] + (int)keyEng[ii] - 48 - 96)) % 26;
        }
        ii++;
        i++;
        if (ii == keyEng.length()) { ii = 0; }
    }
    return Crypted;
}
string Decrypt1(string cEng, string keyEng) {
    string DeCrypted = cEng;  //DeCrypted Crypted
    int i = 0, ii = 0; //Crypted position counter	
    while (DeCrypted[i] != '\0') { //value substitution
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            DeCrypted[i] = 90 - abs((cEng[i] - (int)keyEng[ii] + 48 - 90)) % 26;
        }
        else if (cEng[i] >= 97 && cEng[i] <= 122) {
            DeCrypted[i] = 122 - abs((cEng[i] - (int)keyEng[ii] + 48 - 122)) % 26;
        }
        ii++;
        i++;
        if (ii == keyEng.length()) { ii = 0; }
    }
    return DeCrypted;
}
string Encrypt2(string cEng) {
    string Crypted = cEng;  //crypted Crypted
    int i = 0, ii = 0; //Crypted position counter	
    string Alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    string cryptoAlphabet = "ZXWVTSRQPNMLKJHGFDCBzxwvtsrqpnmlkjhgfdcb";
    while (Crypted[i] != '\0') { //value substitution		
        for (char symbol : Alphabet) {
            if (cEng[i] == symbol) {
                Crypted[i] = cryptoAlphabet[ii];
            }
            ii++;
        }
        i++;
        ii = 0;
    }
    return Crypted;
}
string Decrypt2(string cEng) {
    string DeCrypted = cEng;  //DeCrypted Crypted
    int i = 0, ii = 0; //Crypted position counter	
    string Alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    string cryptoAlphabet = "ZXWVTSRQPNMLKJHGFDCBzxwvtsrqpnmlkjhgfdcb";
    while (DeCrypted[i] != '\0') { //value substitution		
        for (char symbol : Alphabet) {
            if (cEng[i] == symbol) {
                DeCrypted[i] = cryptoAlphabet[ii];
            }
            ii++;
        }
        i++;
        ii = 0;
    }
    return DeCrypted;
}
string Encrypt3(string cEng) {
    string Crypted = cEng;  //DeCrypted Crypted
    int i = 0; //Crypted position counter		
    while (Crypted[i] != '\0') { //value substitution
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            Crypted[i] = 90 - cEng[i] % 65;
        }
        if (cEng[i] >= 97 && cEng[i] <= 122) {
            Crypted[i] = 122 - cEng[i] % 97;
        }
        i++;
    }
    return Crypted;
}
string Decrypt3(string cEng) {

    string DeCrypted = cEng;  //DeCrypted Crypted
    int i = 0; //Crypted position counter		
    while (DeCrypted[i] != '\0') { //value substitution
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            DeCrypted[i] = 90 - cEng[i] % 65;
        }
        if (cEng[i] >= 97 && cEng[i] <= 122) {
            DeCrypted[i] = 122 - cEng[i] % 97;
        }
        i++;
    }
    return DeCrypted;
}
string EncryptForKey(string cEng) {
    int key = 5;
    string cEngCrypted = cEng;  //crypted text
    int i = 0; //text position counter
    while (cEngCrypted[i] != '\0') { //value substitution
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            if ((cEng[i] + key) > 90) { cEngCrypted[i] = (cEng[i] + key) % 90 + 64; }
            else { cEngCrypted[i] = cEng[i] + key; }
        }
        else {
            if ((cEng[i] + key) > 122) { cEngCrypted[i] = (cEng[i] + key) % 122 + 96; }
            else { cEngCrypted[i] = cEng[i] + key; }
        }
        i++;
    }
    return cEngCrypted;
}
string DecryptForKey(string cEng) {
    int keyEng = 5;
    string cEngDeCrypted = cEng;  //crypted text
    int i = 0; //text position counter

    while (cEngDeCrypted[i] != '\0') { //value substitution
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            if ((cEng[i] - keyEng) < 65) {
                cEngDeCrypted[i] = 91 - abs((cEng[i] - keyEng - 65)) % 26;
            }
            else {
                cEngDeCrypted[i] = cEng[i] - keyEng;
            }
        }
        else if (cEng[i] >= 97 && cEng[i] <= 122) {
            if ((cEng[i] - keyEng) < 97) {
                cEngDeCrypted[i] = 123 - abs((cEng[i] - keyEng - 97)) % 26;
            }
            else {
                cEngDeCrypted[i] = cEng[i] - keyEng;
            }
        }
        i++;
    }
    return cEngDeCrypted;
}