#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Field {
public:
    string type;
    string name;

    Field(string type, string name){
        this->type = type;
        this->name = name;
    }
};

class Table {
public:
    string filePath;
    string name;
    int rowCount;
    vector<Field> fields;
    vector<string> fileDeps;
    string fieldIndex;

    Table(){
        this->rowCount = 0;
    }

    Table(string name) {
        this->filePath = "data/tables/" + name + ".dat";
        this->name = name;
        this->rowCount = 0;
    }

    void save(){
        ofstream tableFile;
        tableFile.open(this->filePath);
        tableFile.write((char*)this, sizeof((*this)));
    }

    void addField(string type, string name) {
        this->fields.push_back(Field(type, name));
    }

    static Table load(string name){
        ifstream tableFile;
        tableFile.open("data/tables/" + name + ".dat", ios::in);
        Table table;
        tableFile.read((char*)&table, sizeof(table));
    }

};

class Database {
public:
    int tableCount;
    int rowCount;
    vector<Table> tables;
};

