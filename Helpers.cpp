#if !defined(HELPERS)
#define HELPERS

#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> splitString(string str, string delimiter) {
    string strCopy = str;
    vector<string> tokens;
    size_t pos = 0;
    
    while((pos = strCopy.find(delimiter)) != string::npos) {
        tokens.push_back(strCopy.substr(0, pos));
        strCopy.erase(0, pos + delimiter.length());
    }
    tokens.push_back(strCopy);
    return tokens;
}

#endif
