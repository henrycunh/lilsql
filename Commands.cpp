#if !defined(COMMANDS)
#define COMMANDS

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Helpers.cpp"

class Command {
public:
    
    std::string command;
    std::string description;
    int arg_count;
    std::vector<std::string> arguments;

    Command(std::string command, int arg_count, std::string description){
        this->command = command;
        this->arg_count = arg_count;
        this->description = description;
    }

    void setArguments(std::vector<std::string> arguments){
        this->arguments = arguments;
    }

    static std::vector<Command> getAll(){
        std::vector<Command> commandList;
        std::ifstream commandSourceStream("CommandsSource.csv");
        std::string line;
        while (commandSourceStream.good()) {
            getline(commandSourceStream, line);
            std::vector<std::string> tokens = splitString(line, ",");
            commandList.push_back(Command(tokens[0], std::stoi(tokens[1]), tokens[2]));
        }
        return commandList;
    }

    static Command get(std::string commandString) {
        std::vector<Command> commandList = Command::getAll();
        for (int i = 0; i < commandList.size(); i++) {
            if(commandList[i].command == commandString) {
                return commandList[i];
            }
        }
        return Command::error("Command does not exist");
    }

    static Command error(std::string message) {
        return Command("Invalid", 0, message);
    }
};

#endif