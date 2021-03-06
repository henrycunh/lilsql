// Libraries
#include <iostream>
#include <string>
// Dependencies
#include "Helpers.cpp"
#include "Parser.cpp"
#include "workers/Broker.cpp"

using namespace std;


Database context;
void readFromFile(string destination);
void readFromSTDIN();

int main(int argc, char* argv[]){
    // Lida com o uso de arquivo
    if (argc >= 3) {
        for (int i = 0; i < argc; i++) {
            if (string(argv[i]) == "-f" && i + 1 < argc) {
                readFromFile(string(argv[i++]));
            }
        }
    }
    // Loads database metadata
    context = Database::load();

    // Lida com stdin
    readFromSTDIN();
}

void readFromFile(string destination) {
    
}

void readFromSTDIN(){
    string input;
    cout << "> ";
    while(getline(cin, input)) {
        Command command = Parser::parse(input);
        if (command.command == "EB") {
            break;
        }
        if (command.command == "Invalid") {
            cout << command.description << endl;
        } else {
            Broker::resolve(command, context);
        }
        cout << "> ";
    }
}