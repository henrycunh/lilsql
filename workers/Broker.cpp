#ifndef BROKER
#define BROKER

#include <map>
#include <string>
#include <functional>

#include "Result.cpp"
#include "TableWorker.cpp"
#include "../Commands.cpp"

using namespace std;

// Dispatch table
using workerFunction = function<Result(vector<string>, Database&)>;
map<string, workerFunction> dispatchTable = {
    { "CT", createTable },
    { "RT", removeTable },
    { "AT", showTable },
    { "LT", listTables }
};

class Broker{
public:
    static Result resolve(Command command, Database& context){
        Result result = dispatchTable.find(command.command)->second(command.arguments, context);
        context.save();
        return result;
    }
};

#endif