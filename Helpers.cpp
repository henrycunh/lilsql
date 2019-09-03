#if !defined(HELPERS)
#define HELPERS

#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

const bool IS_DEBUGGING = getenv("DEBUG") != NULL ? string(getenv("DEBUG")) == "true" : false;

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

string getTimestamp(){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
    return oss.str();
}

void log(string message){
    if (IS_DEBUGGING) {
        cout << "[" << getTimestamp() << "][INFO]: " << message << endl;  
    }
}

#endif
