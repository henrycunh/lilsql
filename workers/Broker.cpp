#ifndef BROKER
#define BROKER

#include <map>
#include <string>
#include <functional>

#include "../Commands.cpp"

using namespace std;

class Result {
public:
    string status;
    Result(string status) {
        this->status = status;
    }
};

Result createTable(vector<string> args) {
    for(int i = 0; i < args.size(); i++) {
        cout << args[i] << endl;
    }
    return Result("yes");
}

// Function map
using workerFunction = function<Result(vector<string>)>;
map<string, workerFunction> dispatchTable = {
    { "CT", createTable }
};

class Broker{
public:
    static Result resolve(Command command){
        return dispatchTable.find(command.command)->second(command.arguments);
    }
};



#endif