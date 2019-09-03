#ifndef RESULT
#define RESULT

#include <string>
using namespace std;

class Result {
public:
    string status;
    Result(string status) {
        this->status = status;
    }
};



#endif