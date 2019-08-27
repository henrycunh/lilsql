#if !defined(PARSER)
#define PARSER



#include <string>
#include "Commands.cpp"

class Parser {
public:
    static Command parse(std::string query) {
        if(query == "") {
            return Command::error("Empty query");
        }
        std::vector<std::string> args = splitString(query, " ");
        Command parsedCommand = Command::get(args[0]);
        
        if (parsedCommand.command == "Invalid") {
            return parsedCommand;
        }
        
        int argCount = parsedCommand.arg_count;
         
        if (args.size() - 1 != argCount) {
            return Command::error(args.size() - 1 < argCount ? "Missing arguments" : "Too many arguments");
        }

        parsedCommand.setArguments(std::vector<std::string>(args.begin() + 1, args.end()));
        return parsedCommand;
    }
};

#endif
